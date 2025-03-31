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
		last_node = get_last_node(stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_node **a, char **av)
{
	long	n;

	while (*av)
	{
		if (has_invalid_syntax(*av))
		{
			free_stack(a);
			ft_printf("Error: invalid syntax\n");
			exit(1);
		}
		n = ft_atol(*av);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack(a);
			ft_printf("Error: number out of range\n");
			exit(1);
		}
		if (has_duplicate(*a, (int)n))
		{
			free_stack(a);
			ft_printf("Error: duplicate number\n");
			exit(1);
		}
		append_node(a, (int)n);
		av++;
	}
}
