#include "philo.h"

size_t get_elapsed_time(t_philo *philo);

//print messsage
void print_message(t_philo *philo, int id, char *message) 
{
    size_t elapsed_time;//delete

    pthread_mutex_lock(philo->write_lock);//delete
    elapsed_time = get_now_time() - philo->start_time;//delete
    if (!is_philo_dead(philo))//some condition to check
        printf("%zu %d %s\n", time, id, message);
    pthread_mutex_unlock(philo->write_lock);
}

void print_elapsed_time(t_philo *philo)
{
    size_t elapsed_time;

    elapsed_time = get_now_time() - philo->start_time;
    printf("%zu ", elapsed_time);
}

