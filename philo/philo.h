
#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>   //all pthread functions
# include <sys/time.h>  //gettimeofday
# include <stdlib.h>    //malloc, free
# include <stdio.h>     //printf
# include <unistd.h>    //write, usleep
# include <string.h>    //memset

# define MAX_PHILO 200  //max number of philosophers

typedef struct s_philo
{
	int			id;				// philosopher id
	pthread_t	thread;			// thread for philosopher
	size_t		num_of_philos;	// number of philosophers
	size_t		time_to_die;	// time to die
	size_t		time_to_eat;	// time to eat
	size_t		time_to_sleep;	// time to sleep
	size_t		num_of_eats;		// number of times to eat
}	t_philo;

#endif