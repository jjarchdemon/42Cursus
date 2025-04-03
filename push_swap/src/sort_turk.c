/* ************************************************************************** */

#include "../include/push_swap.h"

static move_a_to_b(t_node **a, t_node **b)
{
	t_node *cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		//function rotate_both()
	else if (!(cheapest->above_median) && cheapest->target->above_median)
		//function rev_rotate_both()
	//prep for push(a, cheapest_node, 'a')
	//prep for push(b, cheapest_node->target, 'b')
	pb(b,a);
}

void	sort_turk(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b,a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b,a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		prep_stack_a(*a, *b);
		move_a_to_b(a, b);//change name?
	}
	sort_three(a);
	while (*b)
	{
		//prep_stack_b(*a, *b);
		//move_b_to_a(a, b);
	}
	//refresh current postion of a
	//ensure smallest number is 
}