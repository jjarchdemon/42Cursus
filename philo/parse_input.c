/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:56 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 13:58:58 by jambatt          ###   ########.fr       */
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


static int ft_atoi(const char *str);

//still need to take care that input is
//1. < INT_MAX
//2. >= 0
//3. is a digit
//no of philosoophers > 0
void	parse_input(t_table *table, char **av)
{
	table->num_of_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]) * 1000;
	table->time_to_eat = ft_atoi(av[3]) * 1000;
	table->time_to_sleep = ft_atoi(av[4]) * 1000;
	//i also need to ensure all the above 3 values are > 60ms, why?
	if (av[5])
		table->num_of_meals = ft_atoi(av[5]);
	// can i have 0 meals?
	else
		table->num_of_meals = -1;//this is a flag, how?
}

/*
static int parse_positive_int(const char *str)
{
	int num;
	num = ft_atoi(str);
	if (num < 0)
	{
		printf("Error: %s must be > 0\n", str);
		return (1);
	}
}
*/

static int ft_atoi(const char *str)
{
	int		sign;
	size_t	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
