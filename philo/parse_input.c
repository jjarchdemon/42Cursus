/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:56 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 17:32:15 by jambatt          ###   ########.fr       */
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

static int is_not_number(const char *str);

int	is_invalid_input(const char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX)	//this is for hardcoded no. of philos 
		return (write(2,"Error: Too many philosophers\n", 29) ,1);
	if (ft_atoi(av[1]) <= 0 || is_not_number(av[1]))
		return (write(2,"Error: Wrong number of philosophers\n", 36) ,1);
	if (ft_atoi(av[2]) <= 0 || is_not_number(av[2]))
		return (write(2,"Error: Wrong time to die\n", 26), 1);
	if (ft_atoi(av[3]) <= 0 || is_not_number(av[3]))
		return (write(2,"Error: Wrong time to eat\n", 26), 1);
	if (ft_atoi(av[4]) <= 0 || is_not_number(av[4]))
		return (write(2,"Error: Wrong time to sleep\n", 28), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || is_not_number(av[5])))
		return (write(2,"Error: Wrong number of meals\n", 30), 1);
	return (0);
}

static int is_not_number(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}