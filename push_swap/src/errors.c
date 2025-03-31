/* ************************************************************************** */

#include "../include/push_swap.h"

int	has_invalid_syntax(char *c)
{
	if (!c || !*c)
		return (1);
    if (!(*c == '+' || *c == '-' || ft_isdigit(*c)))
        return (1);
    if ((*c == '+' || *c == '-') && !ft_isdigit(*(c + 1)))
        return (1);
	c++;
    while (*c)
    {
        if (!ft_isdigit(*c))
            return (1);
		c++;
    }
    return (0);
}

int 	has_duplicate(t_node *a, int n)
{
	t_node *current;

	current = a;
	while (current)
	{
		if (current->num == n)
			return (1);
		current = current->next;
	}
	return (0);
}

//write functions for the 3 error messages in init_stack