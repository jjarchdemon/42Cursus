/* ************************************************************************** */

#include "../include/push_swap.h"

void	prep_stack_a(t_node *a, t_node *b)
{
	//set index & above_median for a
	set_index_n_median(a);
	//set index & above_median for b
	set_index_n_median(b);
	//set target in b for each node in a
	set_target_a(a, b);
	//calculate cost of pushing each node in a to b
	set_pushcost_a(a, b);
	//calculate node with cheapest cost & set it to true
	set_cheapest(a);
}

void	prep_stack_b(t_node *a, t_node *b)
{
	//set index & above_median for a
	set_index_n_median(a);
	//set index & above_median for b
	set_index_n_median(b);
	//set target in a for each node in b
	set_target_b(a, b);
}