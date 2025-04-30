/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:48:35 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/30 15:41:57 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_mtxs_n_forks(t_table *table, t_mtx *fixed_forks_array)
{
	int i;

	i = 0;
	//destroy the forks mutexes in the fork_array
	while (i < table->num_of_philos)
	{
		pthread_mutex_destroy(&fixed_forks_array[i]);
		i++;
	}
	//destroy the mutexes
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->meal_lock);
}

// improved usleep function in milliseconds
void ft_usleep(size_t time)
{
	size_t	start_time;

	start_time = get_now_time();
	while ((get_now_time() - start_time) < time)
		usleep(200);
}

//get the exact time in milliseconds
size_t get_now_time(void)
{
	struct timeval	tv;
	size_t			time;

	if (gettimeofday(&tv, NULL) == -1)
		print_error_message("Error: gettimeofday failed");
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void print_elapsed_time(t_philo *philo)
{
    size_t elapsed_time;

    elapsed_time = get_now_time() - philo->start_time;
    printf("%zu ", elapsed_time);
}