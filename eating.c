#include "philo.h"

static void	acquire_forks_and_eat(t_philo *philo)
{
	t_mtx	*first_fork;
	t_mtx	*second_fork;

	if (philo->l_fork < philo->r_fork)
	{
		first_fork = philo->l_fork;
		second_fork = philo->r_fork;
	}
	else
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	pthread_mutex_lock(first_fork);
	print_with_lock(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	print_with_lock(philo, "has taken a fork");
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 1;
	philo->time_since_meal = get_now_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	print_with_lock(philo, "is eating");
	ft_usleep_interruptible(philo, philo->table->time_to_eat);
}

static void	finish_eating_and_release_forks(t_philo *philo)
{
	t_mtx	*first_fork;
	t_mtx	*second_fork;

	if (philo->l_fork < philo->r_fork)
	{
		first_fork = philo->l_fork;
		second_fork = philo->r_fork;
	}
	else
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

// Always acquire forks in consistent order to prevent deadlock
void	eating(t_philo *philo)
{
	acquire_forks_and_eat(philo);
	finish_eating_and_release_forks(philo);
}
