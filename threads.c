/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:32 by jambatt           #+#    #+#             */
/*   Updated: 2025/07/16 12:01:16 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_monitor(t_table *table, t_mtx *forks_array, pthread_t *observer);
static int	create_philo_threads(t_table *table, t_mtx *forks_array);
static int	join_threads(t_table *table, t_mtx *forks_array, pthread_t observer);

void	create_threads(t_table *table, t_mtx *forks_array)
{
	pthread_t	observer;

	create_monitor(table, forks_array, &observer);
	create_philo_threads(table, forks_array);
	join_threads(table, forks_array, observer);
}

static int	create_monitor(t_table *table, t_mtx *forks_array,
	pthread_t *observer)
{
	if (pthread_create(observer, NULL, &monitor, table->philos_array) != 0)
	{
		destroy_mtxs_n_forks(table, forks_array);
		print_error_message("Waiter thread not created");
		return (1);
	}
	return (0);
}

static int	create_philo_threads(t_table *table, t_mtx *forks_array)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		if (pthread_create(&table->philos_array[i].thread, NULL, &routine,
				&table->philos_array[i]) != 0)
		{
			destroy_mtxs_n_forks(table, forks_array);
			print_error_message("Threads not created");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	join_threads(t_table *table, t_mtx *forks_array, pthread_t observer)
{
	int	i;

	if (pthread_join(observer, NULL) != 0)
	{
		destroy_mtxs_n_forks(table, forks_array);
		print_error_message("Waiter thread didn't join");
		return (1);
	}
	i = 0;
	while (i < table->num_of_philos)
	{
		if (pthread_join(table->philos_array[i].thread, NULL) != 0)
		{
			destroy_mtxs_n_forks(table, forks_array);
			print_error_message("Threads not joined");
			return (1);
		}
		i++;
	}
	return (0);
}
