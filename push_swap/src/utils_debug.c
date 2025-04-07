/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:31:20 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/07 12:31:24 by jambatt          ###   ########.fr       */
/*                                                                            */
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
		return ;
	print_stack_reverse(stack->next);
	ft_printf("%d ", stack->num);
	if (!stack->next)
		ft_printf("\n");
}
