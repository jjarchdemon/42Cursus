/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next)
		temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
