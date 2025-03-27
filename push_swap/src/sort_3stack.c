/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3stack(t_node **stack)
{
	t_node = max;

	max = get_max(*stack);
	if (*stack == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}
