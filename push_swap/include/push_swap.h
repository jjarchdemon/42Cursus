/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:11:18 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/25 17:12:25 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./my_libft/ft_printf.h"	//stddef
# include "./my_libft/get_next_line.h"	//stdlib stdint unistd fcntl
# include "./my_libft/libft.h"		//unistd stdarg

# include <stdbool.h>			//true & false
# include <limits.h>			//int min & max

typedef struct s_node
{
	int	num;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

//handle errors

//stack initiation

//nodes initiation

//stack utils
t_node  *get_last_node(t_node *stack);
int     stack_len(t_node *stack);
bool    is_sorted(t_node *stack);
t_node  *get_min(t_node *stack);
t_node  *get_max(t_node *stack);

//instructions
void    pa(t_node **a, t_node **b);
void    pb(t_node **b, t_node **a);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

//algo
void    sort_3stack(t_node **stack);
#endif
