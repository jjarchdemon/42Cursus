#include "philo.h"

void thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (!is_philo_dead(philo))
	{
		print_elapsed_time(philo);
		printf("%d is thinking\n", philo->id);
	}
	pthread_mutex_unlock(philo->write_lock);
}

void sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (!is_philo_dead(philo))
	{
		print_elapsed_time(philo);
		printf("%d is sleeping\n", philo->id);
	}
	pthread_mutex_unlock(philo->write_lock);
	usleep(philo->table->time_to_sleep * 1000);
}

void eating(t_philo *philo)
{
}