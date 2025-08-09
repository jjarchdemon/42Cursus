/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:07:10 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/09 01:57:20 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//checks if philosopher is dead
static int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(&philo->meal_lock);
	if (get_now_time() - philo->time_since_meal >= time_to_die
		&& philo->eating == 0)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (0);
}

//check if any philosopher is dead
static int	check_if_dead(t_philo *philos_array)
{
	int	i;

	i = 0;
	while (i < philos_array[0].table->num_of_philos)
	{
		if (philosopher_dead(&philos_array[i],
				philos_array[i].table->time_to_die))
		{
			print_with_lock(&philos_array[i], "died");
			set_dead_flag(&philos_array[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

//function to check if all philosophers have eaten the required number of meals
static int	check_if_all_ate(t_philo *philos_array)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos_array[0].table->num_of_meals == -1)
		return (0);
	while (i < philos_array[0].table->num_of_philos)
	{
		pthread_mutex_lock(&philos_array[i].meal_lock);
		if (philos_array[i].meals_eaten >= philos_array[i].table->num_of_meals)
			finished_eating++;
		pthread_mutex_unlock(&philos_array[i].meal_lock);
		i++;
	}
	if (finished_eating == philos_array[0].table->num_of_philos)
	{
		set_dead_flag(&philos_array[0]);
		return (1);
	}
	return (0);
}

//monitor routine
void	*monitor(void *philos_array)
{
	t_philo	*the_philos_array;

	the_philos_array = (t_philo *)philos_array;
	while (1)
	{
		if (check_if_dead(the_philos_array) == 1
			|| check_if_all_ate(the_philos_array) == 1)
			break ;
		usleep(100);  // Check more frequently (0.1ms)
	}
	return (philos_array);
}
