#include "philo.h"

void thinking(t_philo *philo)
{
	print_with_lock(philo, "is thinking");
}

void sleeping(t_philo *philo)
{
	print_with_lock(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}

void eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_with_lock(philo, "has taken a fork");

	//condition for when no of philos is 1
	if (philo->table->num_of_philos == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	
	pthread_mutex_lock(philo->l_fork);
	print_with_lock(philo, "has taken a fork");

	philo->eating = 1;
	print_with_lock(philo, "is eating");

	pthread_mutex_lock(philo->meal_lock);
	philo->time_since_meal = get_now_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);

	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;

	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);

}

