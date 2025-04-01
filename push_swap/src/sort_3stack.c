/* ************************************************************************** */

#include "../include/push_swap.h"

//delete this debug function
void	print_stack(t_node *stack)
{
    while (stack)
    {
        ft_printf("%d ", stack->num);
        stack = stack->next;
    }
    ft_printf("\n");
}

//delete this debug function
void	print_stack_reverse(t_node *stack)
{
	if (!stack)
		return;
	print_stack_reverse(stack->next);
	ft_printf("%d ", stack->num);
	if (!stack->next)
		ft_printf("\n");
}

void	sort_3stack(t_node **stack)
{
	t_node	*max;

	max = get_max(*stack);
	ft_printf("Max: %d\n", max->num); //debug print
	if (*stack == max)
	{
		ra(stack);
		print_stack(*stack); //debug print
	}
	else if ((*stack)->next == max)
	{
		rra(stack);
		print_stack(*stack); //debug print
	}
	if ((*stack)->num > (*stack)->next->num)
	{
		sa(stack);
		print_stack(*stack); //debug print
	}
}

