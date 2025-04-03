/* ************************************************************************** */

#include "../include/push_swap.h"

//store ref to the next node in temp so as to not lose the
//pointer when freeing the current node
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}