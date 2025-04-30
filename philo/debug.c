/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:57:20 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/30 15:57:28 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//debug function for printing the table state

void print_table_state(t_table *table)
{
    size_t i;

    i = 0;
    printf("Number of Philosophers: %zu\n", (size_t)table->num_of_philos);
    printf("Time to Die (ms): %zu\n", table->time_to_die);
    printf("Time to Eat (ms): %zu\n", table->time_to_eat);
    printf("Time to Sleep (ms): %zu\n", table->time_to_sleep);
    printf("Number of Meals: %zu\n", (size_t)table->num_of_meals);
    printf("Dead Flag: %s\n", table->dead_flag ? "true" : "false");
    printf("Table pointer: %p\n", (void *)table);
    while (i < (size_t)table->num_of_philos)
    {
        printf("Philosopher ID: %d\n", table->philos_array[i].id);
        printf("  Eating: %d\n", table->philos_array[i].eating);
        printf("  Meals Eaten: %d\n", table->philos_array[i].meals_eaten);
        printf("  Start Time: %zu\n", table->philos_array[i].start_time);
        printf("  Time Since Last Meal: %zu\n", table->philos_array[i].time_since_meal);
        printf("  Left Fork ID: %p\n", (void *)table->philos_array[i].l_fork);
        printf("  Right Fork ID: %p\n", (void *)table->philos_array[i].r_fork);
        printf("  Table Pointer: %p\n", (void *)table->philos_array[i].table);
        i++;
    }
}