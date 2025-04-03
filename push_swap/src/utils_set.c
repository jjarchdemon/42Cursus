/* ************************************************************************** */

#include "../include/push_swap.h"

//set index & above_median
void	set_index_n_median(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}



//set target in b for each node in a
void set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > best_match)
			{
				best_match = current_b->num;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

//set target in a for each node in b
void set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < best_match)
			{
				best_match = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}