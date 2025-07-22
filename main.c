/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:32 by jambatt           #+#    #+#             */
/*   Updated: 2025/07/22 11:11:07 by jambatt          ###   ########.fr       */
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
	t_philo	philos_array[PHILO_MAX];
	t_mtx	forks_array[PHILO_MAX];

	if (ac != 5 && ac != 6)
		return (write(2, "Error: Wrong number of arguments\n", 33), 1);
	if (is_invalid_input(av))
		return (write(2, "Error: Invalid input\n", 22), 1);
	init_table(&table, av, philos_array);
	init_forks(av, forks_array);
	init_philos(&table, av, forks_array);
	create_threads(&table, forks_array);
	destroy_mtxs_n_forks(&table, forks_array);
	return (0);
}
