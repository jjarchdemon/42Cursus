#include "philo.h"

//print messsage
void print_message(t_philo *philo, int id, char *message) 
{
    size_t time;

    pthread_mutex_lock(philo->write_lock);
    time = get_now_time() - philo->start_time;
    //some condition to check
        printf("%zu %d %s\n", time, id, message);
    pthread_mutex_unlock(philo->write_lock);
}