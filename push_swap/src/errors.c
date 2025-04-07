/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:29:48 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/07 13:32:08 by jambatt          ###   ########.fr       */
/*                                                                            */
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

int	has_duplicate(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == n)
			return (1);
		a = a->next;
	}
	return (0);
}

//write functions for the 3 error messages in init_stack
void	handle_invalid_syntax(t_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

void	handle_overflow(t_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

void	handle_duplicate(t_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
