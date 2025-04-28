/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:57:38 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 17:29:25 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_table(t_table *table, const char **av, t_philo *fixed_philos_array)
{
    table->num_of_philos = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        table->num_of_meals = (size_t)ft_atoi(av[5]);
    else
        table->num_of_meals = INT_MAX; // No limit on meals

    table->dead_flag = false;
    pthread_mutex_init(&table->dead_lock, NULL);    //init dead_lock
    pthread_mutex_init(&table->write_lock, NULL);   //init write_lock
    pthread_mutex_init(&table->meal_lock, NULL);    //init meal_lock
    table->philos_array = fixed_philos_array;       //init philos_array    
}

void init_philos(t_table *table, const char **av, t_mtx *fixed_forks_array)
{
    int     i;

    i = 0;
    while (i < ft_atoi(av[1]))
    {
        table->philos_array[i].id = i + 1; // Philosopher IDs start from 1
        table->philos_array[i].eating = 0;
        table->philos_array[i].meals_eaten = 0;
        //init time_since_meal
        table->philos_array[i].table = table;
        //init start_time
        table->philos_array[i].is_dead = false;//careful with this
        table->philos_array[i].l_fork = &fixed_forks_array[i];
        if (i == 0)
            table->philos_array[i].r_fork = &fixed_forks_array[ft_atoi(av[1]) - 1];
        else
            table->philos_array[i].r_fork = &fixed_forks_array[i - 1];     
        i++;
    }
}

void init_forks(const char **av, t_mtx *fixed_forks_array)
{
    int i;

    i = 0;
    while (i < ft_atoi(av[1]))
    {
        pthread_mutex_init(&fixed_forks_array[i], NULL); //understand this
        i++;
    }
}