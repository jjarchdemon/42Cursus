/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:48:35 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/09 01:57:20 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

// improved usleep function in milliseconds
void	ft_usleep(size_t time)
{
	size_t	start_time;
	size_t	elapsed;

	start_time = get_now_time();
	while (1)
	{
		elapsed = get_now_time() - start_time;
		if (elapsed >= time)
			break ;
		if (time - elapsed > 10)
			usleep(5000);  // Sleep for 5ms if we have more than 10ms left
		else
			usleep(100);   // Sleep for 0.1ms for precision
	}
}

//get the exact time in milliseconds
size_t	get_now_time(void)
{
	struct timeval	tv;
	size_t			time;

	if (gettimeofday(&tv, NULL) == -1)
		print_error_message("Error: gettimeofday failed");
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	print_elapsed_time(t_philo *philo)
{
	size_t	elapsed_time;

	elapsed_time = get_now_time() - philo->start_time;
	printf("%zu ", elapsed_time);
}

//helper function to print a message with lock
void	print_with_lock(t_philo *philo, const char *message)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (!get_dead_flag(philo))
	{
		print_elapsed_time(philo);
		printf("%d %s\n", philo->id, message);
	}
	pthread_mutex_unlock(&philo->table->print_lock);
}

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
