/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:07:48 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/09 18:21:31 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_with_lock(philo, "is thinking");
	if (philo->table->num_of_philos > 2)
		ft_usleep_interruptible(philo, 1);
}

void	sleeping(t_philo *philo)
{
	print_with_lock(philo, "is sleeping");
	ft_usleep_interruptible(philo, philo->table->time_to_sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_with_lock(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_with_lock(philo, "has taken a fork");
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 1;
	philo->time_since_meal = get_now_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	print_with_lock(philo, "is eating");
	ft_usleep_interruptible(philo, philo->table->time_to_eat);
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	is_philo_dead(t_philo *philo)
{
	return (get_dead_flag(philo));
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->table->num_of_philos == 1)
	{
		print_with_lock(philo, "has taken a fork");
		while (!is_philo_dead(philo))
			ft_usleep_interruptible(philo, 1);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2);//why only this delay amt?
	while (!is_philo_dead(philo))
	{
		eating(philo);
		if (is_philo_dead(philo))
			break ;
		sleeping(philo);
		if (is_philo_dead(philo))
			break ;
		thinking(philo);
		if (is_philo_dead(philo))
			break ;
	}
	return (NULL);
}
