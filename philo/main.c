#include "philo.h"

/*
 *         - num_of_philos
 *         |
 *         |  - time_to_die
 *         |  |
 *         |  |   - time_to_eat
 *         |  |   |
 *         |  |   |   - time_to_sleep
 *         |  |   |   |
 *         |  |   |   |   - max. no of meals
 *         |  |   |   |   |
 * ./philo 5 800 200 200 [5]
 */

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		parse_input(&table, av);//yet to implement error handling
		//2) init the table state
		init_table(&table);//TODO
		print_table_state(&table);//delete this later
		//3) start simulation
		//start_dinner(&table);//TODO
		//4) end simulation cleanly
		//clean(&table);//TODO
	}
	else
	{
		printf("Please input correct arguments\n");
		return (1);
	}
	return (0);
}
