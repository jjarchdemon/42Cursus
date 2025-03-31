/* ************************************************************************** */

#include "../include/push_swap.h"
t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack->next)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);//is this enough?
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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
