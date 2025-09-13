/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:59:31 by jambatt           #+#    #+#             */
/*   Updated: 2025/09/13 12:59:35 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_dead_flag(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->table->dead_lock);
	dead = philo->table->dead_flag;
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (dead);
}

void	set_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_lock);
	philo->table->dead_flag = 1;
	pthread_mutex_unlock(&philo->table->dead_lock);
}

void	destroy_mtxs_n_forks(t_table *table, t_mtx *forks_array)
{
	int	i;

	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->dead_lock);
	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_mutex_destroy(&forks_array[i]);
		pthread_mutex_destroy(&table->philos_array[i].meal_lock);
		i++;
	}
}
