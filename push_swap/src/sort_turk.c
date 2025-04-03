/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node, bool rev)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
	{
		if (!rev)
			rr(a, b);
		else
			rrr(a, b);
		//set_index_n_median(*a);//why is this redundant?
		//set_index_n_median(*b);//why is this redundant?
	}
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest, false);//function rotate_both()
	else if (!(cheapest->above_median) && cheapest->target->above_median)
		rotate_both(a, b, cheapest, true);//function rev_rotate_both()
	push_to_top(a, cheapest, 'a');
	push_to_top(b, cheapest->target, 'b');
	pb(b, a);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	push_to_top(a, (*b)->target, 'a');//prep for push(b, cheapest_node, 'b')
	pa(a, b);
}

static void	push_min_to_top(t_node **a)
{
	while ((*a)->num != get_min(*a)->num)
	{
		if (get_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_turk(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		prep_stack_a(*a, *b);
		move_a_to_b(a, b);//change name?
	}
	sort_three(a);
	while (*b)
	{
		prep_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index_n_median(*a);
	push_min_to_top(a);
}