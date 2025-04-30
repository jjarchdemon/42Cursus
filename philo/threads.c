#include "philo.h"

int is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->is_dead)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		ft_usleep(1);  // to avoid deadlock? and why 1?
	while (!is_philo_dead(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (philosopher);
}

int	create_threads(t_table *table, t_mtx *fixed_forks_array)
{
	pthread_t observer;
	int i;

	if (pthread_create(&observer, NULL, &monitor, table->philos_array) != 0)
	{
		destroy_mtxs_n_forks(table, fixed_forks_array);
		print_error_message("Waiter thread not created");
		return (1);
	}
	i = 0;
	while (i < table->num_of_philos)
	{
		if (pthread_create(&table->philos_array[i].thread, NULL, &routine,
				&table->philos_array[i]) != 0)
		{
			destroy_mtxs_n_forks(table, fixed_forks_array);
			print_error_message("Threads not created");
			return (1);
		}
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
	{
		destroy_mtxs_n_forks(table, fixed_forks_array);
		print_error_message("Waiter thread didn't join");
		return (1);
	}
	while (i < table->num_of_philos)
	{
		if (pthread_join(table->philos_array[i].thread, NULL) != 0)
		{
			destroy_mtxs_n_forks(table, fixed_forks_array);
			print_error_message("Threads not joined");
			return (1);
		}
		i++;
	}
	return (0);
}