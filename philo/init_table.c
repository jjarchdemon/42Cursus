#include "philo.h"

/*
typedef struct s_table
{
	size_t	num_of_philos;	// done by parse_input
	size_t	time_to_die;	// done by parse_input
    size_t	time_to_eat;	// done by parse_input
	size_t	time_to_sleep;	// done by parse_input
	size_t	num_of_meals;	// done by parse_input

	t_philo	*philos_array;		//malloc done 
	t_fork	*forks_array;		//malloc done 
	size_t	start_simulation;   //------>still to do
	bool	end_simulation;	    // set to false
}	t_table;
*/

static void init_forks(t_table *table);
static void init_philos(t_table *table);

void init_table(t_table *table)
{
    table->end_simulation = false;
    table->philos_array = malloc(sizeof(t_philo) * table->num_of_philos);
    if (!table->philos_array)
    {
        printf("Error: Memory allocation failed\n");
        return;
    }
        table->forks_array = malloc(sizeof(t_fork) * table->num_of_philos);
    if (!table->forks_array)
    {
        free(table->philos_array);//free the philos in the array as well?
        printf("Error: Memory allocation failed\n");
        return;
    }
    init_forks(table);
    init_philos(table);
    table->start_simulation = 0;//not sure
}

static void init_forks(t_table *table)
{
    size_t i;

    i = 0;
    while (i < table->num_of_philos)
    {
        table->forks_array[i].fork_id = i+1; // Fork IDs start from 1
        if (pthread_mutex_init(&table->forks_array[i].fork, NULL) != 0)
        {
            printf("Error: Mutex initialization failed for fork %zu\n", i);
            // Cleanup code here?
            return;
        }
        i++;
    }
}

static void init_philos(t_table *table)
{
    size_t i;

    i = 0;
    while (i < table->num_of_philos)
    {
        table->philos_array[i].id = i+1; // Philosopher IDs start from 1
        table->philos_array[i].meals_eaten = 0;
        table->philos_array[i].is_full = false;
        table->philos_array[i].time_since_meal = 0;
        table->philos_array[i].l_fork = &(table->forks_array[i]);
        table->philos_array[i].r_fork = &table->forks_array[(i + 1) % table->num_of_philos];
        // what is the logic for the right fork?
        table->philos_array[i].thread_id = 0;   //correct to init pthread_t?
        table->philos_array[i].table = table;
        i++;
    }
}

//write a debug function to print the table state