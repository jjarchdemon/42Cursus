#include "philo.h"

/*
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
*/



