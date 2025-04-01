/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol(char *s)
{
	long	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*s <= 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num * sign);
}

static void	append_node(t_node **stack, int n)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack); //reqd?
		ft_printf("Error in memory allocation"); //reqd?
		return ;
	}
	new_node->num = n;
	new_node->next = NULL;
	new_node->cheapest = 0; //why is this here?
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (has_invalid_syntax(av[i]))
			handle_invalid_syntax(a);
		n = ft_atol(av[i]);
		ft_printf("Parsed number: %d\n", n); //debug print
		if (n > INT_MAX || n < INT_MIN)
			handle_overflow(a);
		if (has_duplicate(*a, (int)n))
		{
			ft_printf("Duplicate detected for: %d\n", (int)n); // Debug print
			handle_duplicate(a);
		}
		append_node(a, (int)n);
		ft_printf("Stack after adding %d: ", (int)n); // Debug print
        print_stack(*a); // Debug print
		i++;
	}
}
