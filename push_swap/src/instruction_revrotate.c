/* ************************************************************************** */

#include "../include/push_swap.h"

static void	revrotate(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = get_last_node(*stack);
	temp->prev->next = NULL;
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
	temp->prev = NULL;
}

void	rra(t_node **a)
{
	revrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	revrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	revrotate(a);
	revrotate(b);
	ft_printf("rrr\n");
}
