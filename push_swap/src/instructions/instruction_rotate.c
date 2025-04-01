/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = get_last_node(*stack);
	temp->prev->next = temp;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
