/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:08 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/28 17:26:43 by jambatt          ###   ########.fr       */
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

# define PHILO_MAX 200

typedef struct s_table t_table;

typedef pthread_mutex_t t_mtx;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;				// philosopher id
	int			eating;
	int			meals_eaten;	// no. of meals eaten
	size_t		time_since_meal;// time since last meal | last_meal
	
	t_table		*table;			// pointer to table state, for the arguments
	size_t		start_time;		// start time of the simulation?
	bool 		is_dead;		// is philosopher dead | int *dead
	
	t_mtx		*l_fork;		// pointer to left fork
	t_mtx		*r_fork;		// pointer to right fork
	t_mtx		*write_lock;
	t_mtx		*dead_lock;
	t_mtx		*meal_lock;
}	t_philo;

typedef struct s_table
{
	size_t	num_of_philos;	// number of philosophers
	size_t	time_to_die;	// time to die
	size_t	time_to_eat;	// time to eat
	size_t	time_to_sleep;	// time to sleep
	size_t	num_of_meals;	// number of times to eat

	bool		dead_flag; 
	t_mtx	dead_lock;
	t_mtx	write_lock;
	t_mtx	meal_lock;
	t_philo	*philos_array;	// array of philosophers
}	t_table;

int		is_invalid_input(const char **av);

void init_table(t_table *table, const char **av, t_philo *fixed_philos_array);
void init_philos(t_table *table, const char **av, t_mtx *fixed_forks_array);
void init_forks(const char **av, t_mtx *fixed_forks_array);


void	print_table_state(t_table *table);

int ft_atoi(const char *str);
size_t get_now_time(void);
#endif
