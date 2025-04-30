/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:48:35 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/30 13:52:43 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *str)
{
	int		sign;
	size_t	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}

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
	return (0);
}

//get the exact time in milliseconds
size_t get_now_time(void)
{
	struct timeval	tv;
	size_t			time;

	if (gettimeofday(&tv, NULL) == -1)
		write(2,"Error: gettimeofday failed\n", 27);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void print_elapsed_time(t_philo *philo)
{
    size_t elapsed_time;

    elapsed_time = get_now_time() - philo->start_time;
    printf("%zu ", elapsed_time);
}