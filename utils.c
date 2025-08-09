/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:48:35 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/09 18:20:50 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// improved usleep function in milliseconds
void	ft_usleep(size_t time)
{
	size_t	start;
	size_t	current;

	start = get_now_time();
	while (1)
	{
		current = get_now_time();
		if (current - start >= time)
			break ;
		usleep(500);
	}
}

// New function that can be interrupted by death
void	ft_usleep_interruptible(t_philo *philo, size_t time)
{
	size_t	start;
	size_t	current;

	start = get_now_time();
	while (1)
	{
		if (get_dead_flag(philo))
			return ;
		current = get_now_time();
		if (current - start >= time)
			break ;
		usleep(500);
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
