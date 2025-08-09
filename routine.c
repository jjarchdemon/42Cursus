/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:07:48 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/09 19:00:07 by joseph           ###   ########.fr       */
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
		if (is_philo_dead(philo))
			break ;
	}
	return (NULL);
}
