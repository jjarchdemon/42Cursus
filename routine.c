/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:07:48 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/01 15:24:34 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_with_lock(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	size_t	sleep_start;
	size_t	elapsed;

	print_with_lock(philo, "is sleeping");
	sleep_start = get_now_time();
	while (!is_philo_dead(philo))
	{
		elapsed = get_now_time() - sleep_start;
		if (elapsed >= philo->table->time_to_sleep)
			break ;
		usleep(500);
	}
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
	philo->eating = 1;
	print_with_lock(philo, "is eating");
	pthread_mutex_lock(philo->meal_lock);
	philo->time_since_meal = get_now_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		ft_usleep(1);
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
