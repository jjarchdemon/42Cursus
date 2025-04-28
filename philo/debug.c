/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:57:20 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 17:27:50 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//debug function for printing the table state
/*
void print_table_state(t_table *table)
{
    size_t i;

    i = 0;
    printf("Number of Philosophers: %zu\n", table->num_of_philos);
    printf("Simulation Start: %zu\n", table->start_simulation);
    printf("Simulation End: %s\n", table->end_simulation ? "true" : "false");
    while (i < table->num_of_philos)
    {
        printf("Philosopher %zu:\n", table->philos_array[i].id);
        printf("  Meals Eaten: %zu\n", table->philos_array[i].meals_eaten);
        printf("  Is Full: %s\n", table->philos_array[i].is_full ? "true" : "false");
        printf("  Time Since Last Meal: %zu\n", table->philos_array[i].time_since_meal);
        printf("  Left Fork ID: %zu\n", table->philos_array[i].l_fork->fork_id);
        printf("  Right Fork ID: %zu\n", table->philos_array[i].r_fork->fork_id);
        printf("  Thread ID: %lu\n", (unsigned long)table->philos_array[i].thread_id);
        printf("  Table Pointer: %p\n", (void *)table->philos_array[i].table);
        i++;
    }
    i = 0;
    printf("Forks Array: %p\n", (void *)table->forks_array);
    while (i < table->num_of_philos)
    {
        printf("Fork %zu:\n", table->forks_array[i].fork_id);
        i++;
    }
}
*/