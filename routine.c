/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:07:48 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/09 02:09:23 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_with_lock(philo, "is thinking");
	// Add minimal thinking time to prevent immediate re-eating
	if (philo->table->num_of_philos > 2)
		ft_usleep(1);
}

void	sleeping(t_philo *philo)
{
	print_with_lock(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}

void	eating(t_philo *philo)
{
	t_mtx	*first_fork;
	t_mtx	*second_fork;

	if (philo->l_fork < philo->r_fork)
	{
		first_fork = philo->l_fork;
		second_fork = philo->r_fork;
	}
	else
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	pthread_mutex_lock(first_fork);
	print_with_lock(philo, "has taken a fork");
	if (philo->table->num_of_philos == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(first_fork);
		return ;
	}
	pthread_mutex_lock(second_fork);
	print_with_lock(philo, "has taken a fork");
	print_with_lock(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 1;
	philo->time_since_meal = get_now_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

int	is_philo_dead(t_philo *philo)
{
	return (get_dead_flag(philo));
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	// Stagger philosophers more effectively
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2);
	while (!is_philo_dead(philo))
	{
		eating(philo);
		if (is_philo_dead(philo))
			break ;
		sleeping(philo);
		if (is_philo_dead(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}
