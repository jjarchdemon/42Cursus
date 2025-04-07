/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:30:28 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/07 13:33:46 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//set index & above_median for a
//set index & above_median for b
//set target in b for each node in a
//calculate cost of pushing each node in a to b
//calculate node with cheapest cost & set it to true
void	prep_stack_a(t_node *a, t_node *b)
{
	set_index_n_median(a);
	set_index_n_median(b);
	set_target_a(a, b);
	set_pushcost_a(a, b);
	set_cheapest(a);
}

//set index & above_median for a
//set index & above_median for b
//set target in a for each node in b
void	prep_stack_b(t_node *a, t_node *b)
{
	set_index_n_median(a);
	set_index_n_median(b);
	set_target_b(a, b);
}
