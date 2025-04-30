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
	pthread_mutex_lock(philo->r_fork);
	
	pthread_mutex_lock(philo->write_lock);
	if (!is_philo_dead(philo))
	{
		print_elapsed_time(philo);
		printf("%d has taken a fork\n", philo->id);
	}
	pthread_mutex_unlock(philo->write_lock);

	//condition for when no of philos is 1
	if (philo->table->num_of_philos == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	
	pthread_mutex_lock(philo->l_fork);
	
	pthread_mutex_lock(philo->write_lock);
	if (!is_philo_dead(philo))
	{
		print_elapsed_time(philo);
		printf("%d has taken a fork\n", philo->id);
	}
	pthread_mutex_unlock(philo->write_lock);

	philo->eating = 1;// convert this to bool?
	pthread_mutex_lock(philo->write_lock);
	if (!is_philo_dead(philo))
	{
		print_elapsed_time(philo);
		printf("%d is eating\n", philo->id);
	}
	pthread_mutex_unlock(philo->write_lock);

	pthread_mutex_lock(philo->meal_lock);
	philo->time_since_meal = get_now_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);

	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;

	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);

}