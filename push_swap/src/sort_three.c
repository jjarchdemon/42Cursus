/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_node **stack)
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