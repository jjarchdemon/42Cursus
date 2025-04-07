/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:33:02 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/07 12:33:06 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = temp->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	if (!*dst)
		*dst = temp;
	else
	{
		(*dst)->prev = temp;
		temp->next = *dst;
		*dst = temp;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
