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
		target_node = NULL;
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
		target_node = NULL;
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

//calculate cost of pushing each node in a to b
void	set_pushcost_a(t_node *a, t_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}

//calculate node with cheapest cost & set it to true
void	set_cheapest(t_node *stack)
{
	t_node	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}