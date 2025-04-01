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
	if (!a)
		return (0);
	while (a)
	{
		ft_printf("Comparing %d with %d\n", a->num, n); // Debug print
		if (a->num == n)
		{
			ft_printf("duplicate found: %d\n", a->num); //debug print
			return (1);
		}
		a = a->next;
	}
	return (0);
}

//write functions for the 3 error messages in init_stack

void	handle_invalid_syntax(t_node **a)
{
	free_stack(a);
	ft_printf("Error: invalid syntax\n");
	exit(1);
}

void	handle_overflow(t_node **a)
{
	free_stack(a);
	ft_printf("Error: number out of range\n");
	exit(1);
}

void	handle_duplicate(t_node **a)
{
	free_stack(a);
	ft_printf("Error: duplicate number\n");
	exit(1);
}