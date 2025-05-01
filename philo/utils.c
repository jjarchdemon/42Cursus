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

void destroy_mtxs_n_forks(t_table *table, t_mtx *forks_array)
{
	int i;

	//destroy the mutexes
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->meal_lock);
	i = 0;
	//destroy the forks mutexes in the fork_array
	while (i < table->num_of_philos)
	{
		pthread_mutex_destroy(&forks_array[i]);
		i++;
	}
}

// improved usleep function in milliseconds
void ft_usleep(size_t time)
{
	size_t	start_time;

	start_time = get_now_time();
	while ((get_now_time() - start_time) < time)
		usleep(500);
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

//helper function to print a message with lock
void print_with_lock(t_philo *philo, const char *message)
{
	pthread_mutex_lock(philo->write_lock);
	if (!is_philo_dead(philo))
	{
		print_elapsed_time(philo);
		printf("%d %s\n", philo->id, message);
	}
	pthread_mutex_unlock(philo->write_lock);
}