/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:32 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 17:31:27 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 *         - num_of_philos
 *         |
 *         |  - time_to_die
 *         |  |
 *         |  |   - time_to_eat
 *         |  |   |
 *         |  |   |   - time_to_sleep
 *         |  |   |   |
 *         |  |   |   |   - max. no of meals
 *         |  |   |   |   |
 * ./philo 5 800 200 200 [5]
 */

int	main(int ac, const char **av)
{
	t_table	table;
	t_philo	fixed_philos_array[PHILO_MAX];	//hardocoded max. no of philosophers
	t_mtx	fixed_forks_array[PHILO_MAX];	//same for forks
	if (ac != 5 && ac != 6)
		return (write(2,"Error: Wrong number of arguments\n", 33), 1);
	if (is_invalid_input(av))
		return (write(2,"Error: Invalid input\n", 22), 1);
	//1)init the table
	init_table(&table, av, fixed_philos_array);
	init_forks(av, fixed_forks_array);
	init_philos(&table, av, fixed_forks_array);
	
	print_table_state(&table);
	//2)create the threads
	//3)destroy the threads
	return (0);
}
