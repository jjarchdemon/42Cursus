/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:57:38 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 17:29:25 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_table(t_table *table, const char **av, t_philo *philos_array)
{
    table->num_of_philos = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        table->num_of_meals = ft_atoi(av[5]);
    else
        table->num_of_meals = -1; // why ?

    table->dead_flag = 0;
    pthread_mutex_init(&table->dead_lock, NULL);    //init dead_lock
    pthread_mutex_init(&table->write_lock, NULL);   //init write_lock
    pthread_mutex_init(&table->meal_lock, NULL);    //init meal_lock
    table->philos_array = philos_array;       //init philos_array    
}

void init_philos(t_table *table, const char **av, t_mtx *forks_array)
{
    int     i;

    i = 0;
    while (i < ft_atoi(av[1]))
    {
        table->philos_array[i].id = i + 1; // Philosopher IDs start from 1
        table->philos_array[i].eating = 0;
        table->philos_array[i].meals_eaten = 0;
        table->philos_array[i].table = table;
        table->philos_array[i].start_time = get_now_time();
        table->philos_array[i].time_since_meal = get_now_time();
        table->philos_array[i].write_lock = &table->write_lock;
        table->philos_array[i].meal_lock = &table->meal_lock;
        table->philos_array[i].dead_lock = &table->dead_lock;
        table->philos_array[i].dead = &table->dead_flag;
        table->philos_array[i].l_fork = &forks_array[i];
        if (i == 0)
            table->philos_array[i].r_fork = &forks_array[ft_atoi(av[1]) - 1];
        else
            table->philos_array[i].r_fork = &forks_array[i - 1];
        i++;
    }
}

void init_forks(const char **av, t_mtx *forks_array)
{
    int i;

    i = 0;
    while (i < ft_atoi(av[1]))
    {
        pthread_mutex_init(&forks_array[i], NULL);
        i++;
    }
}