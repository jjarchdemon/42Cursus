/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:30:08 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/07 13:00:18 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol(char *s)
{
	long	num;
	int		sign;

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
		free_stack(stack);
		ft_printf("Error in memory allocation");
		return ;
	}
	new_node->num = n;
	new_node->next = NULL;
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
		if (n > INT_MAX || n < INT_MIN)
			handle_overflow(a);
		if (has_duplicate(*a, (int)n))
		{
			handle_duplicate(a);
		}
		append_node(a, (int)n);
		i++;
	}
}
