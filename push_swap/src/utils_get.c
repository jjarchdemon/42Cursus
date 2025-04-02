/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*get_min(t_node *stack)
{
	t_node	*current_min;

	if (!stack)
		return (NULL);
	current_min = stack;
	while (stack)
	{
		if (stack->num < current_min->num)
			current_min = stack;
		stack = stack->next;
	}
	return (current_min);
}

t_node	*get_max(t_node *stack)
{
	t_node	*current_max;

	if (!stack)
		return (NULL);
	current_max = stack;
	while (stack)
	{
		if (stack->num > current_max->num)
			current_max = stack;
		stack = stack->next;
	}
	return (current_max);
}

t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}