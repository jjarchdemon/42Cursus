/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:08 by jambatt           #+#    #+#             */
/*   Updated: 2025/08/09 18:17:02 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>   //all pthread functions
# include <sys/time.h>  //gettimeofday
# include <stdio.h>     //printf
# include <unistd.h>    //write, usleep

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

typedef struct s_table	t_table;

typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			eating;
	int			meals_eaten;
	size_t		time_since_meal;
	size_t		start_time;
	int			*dead;
	t_mtx		*l_fork;
	t_mtx		*r_fork;
	t_mtx		meal_lock;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	int		num_of_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		num_of_meals;
	int		dead_flag;
	t_mtx	print_lock;
	t_mtx	dead_lock;
	t_philo	*philos_array;
}	t_table;

//parsing input
int		is_invalid_input(const char **av);

// initialization
void	init_table(t_table *table, const char **av, t_philo *philos_array);
void	init_philos(t_table *table, const char **av, t_mtx *forks_array);
void	init_forks(const char **av, t_mtx *forks_array);

//threads
void	create_threads(t_table *table, t_mtx *forks_array);

//routine
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);

//two thread things
void	*routine(void *philosopher);
void	*monitor(void *philos_array);
int		is_philo_dead(t_philo *philo);

//utils.c
int		ft_atoi(const char *str);
size_t	get_now_time(void);
void	destroy_mtxs_n_forks(t_table *table, t_mtx *forks_array);
void	ft_usleep(size_t time);
void	ft_usleep_interruptible(t_philo *philo, size_t time);
void	print_error_message(char *message);
void	print_with_lock(t_philo *philo, const char *message);
int		get_dead_flag(t_philo *philo);
void	set_dead_flag(t_philo *philo);

// debug
void	print_table_state(t_table *table);
#endif
