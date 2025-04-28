/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:08 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 13:58:15 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>   //all pthread functions
# include <sys/time.h>  //gettimeofday
# include <stdlib.h>    //malloc, free
# include <stdio.h>     //printf
# include <unistd.h>    //write, usleep
# include <string.h>    //memset
# include <stdbool.h>	//bool type
# include <limits.h>    //INT_MAX 

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

typedef struct s_table t_table;

typedef pthread_mutex_t t_mtx;

typedef struct s_fork
{
	size_t	fork_id;
	t_mtx	fork;
}	t_fork;

typedef struct s_philo
{
	size_t			id;			// philosopher id
	size_t		meals_eaten;	// no. of meals eaten
	bool		is_full;		// is philosopher full
	size_t		time_since_meal;// time since last meal
	t_fork		*l_fork;		// pointer to left fork
	t_fork		*r_fork;		// pointer to right fork
	pthread_t	thread_id;
	t_table		*table;			// pointer to table state
}	t_philo;

typedef struct s_table
{
	size_t	num_of_philos;	// number of philosophers
	size_t	time_to_die;	// time to die
	size_t	time_to_eat;	// time to eat
	size_t	time_to_sleep;	// time to sleep
	size_t	num_of_meals;	// number of times to eat
	t_philo	*philos_array;	// array of philosophers
	t_fork	*forks_array;	// array of forks
	size_t	start_simulation;//when simulation starts
	bool	end_simulation;	// triggered when a philo dies or
							// all philos are full
}	t_table;




void	parse_input(t_table *table, char **av);
void	init_table(t_table *table);

void	print_table_state(t_table *table);


#endif
