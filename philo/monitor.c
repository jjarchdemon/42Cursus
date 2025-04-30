#include "philo.h"

//checks if philosopher is dead
int philosopher_dead(t_philo *philo, size_t time_to_die)
{
    pthread_mutex_lock(philo->meal_lock);
    if (get_now_time() - philo->time_since_meal >= time_to_die && philo->eating == 0)
    {
        pthread_mutex_unlock(philo->meal_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->meal_lock);
    return (0);
}

//check if any philosopher is dead
int check_if_dead(t_philo *fixed_philos_array)
{
    int i;

    i = 0;
    while (i < fixed_philos_array[0].table->num_of_philos)
    {
        if (philosopher_dead(&fixed_philos_array[i], fixed_philos_array[i].table->time_to_die))
        {
            pthread_mutex_lock(fixed_philos_array[i].write_lock);
	        if (!is_philo_dead(fixed_philos_array[i]))
	        {
		        print_elapsed_time(&fixed_philos_array[i]);
		        printf("%d died\n", fixed_philos_array[i].id);
	        }
	        pthread_mutex_unlock(fixed_philos_array[i].write_lock);
            
            pthread_mutex_lock(fixed_philos_array[0].dead_lock);
            fixed_philos_array[i].is_dead = true;
            pthread_mutex_unlock(fixed_philos_array[0].dead_lock);
            
            return (1);
        }
        i++;
    }

}

//function to check if all philosophers have eaten the required number of meals



//monitor routine

void *monitor(void *fixed_philos_array)
{
    t_philo	*the_philos_array;
    int		i;

    the_philos_array = (t_philo *)fixed_philos_array;
    while (1)
    {
        if (check_if_dead(the_philos_array) == 1 || check_if_all_ate(the_philos_array) == 1)
            break;
    }
    return (fixed_philos_array); 
}