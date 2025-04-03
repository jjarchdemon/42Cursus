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
# include <limits.h>			//int/long min & max

typedef struct s_node
{
	int				num;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

//algo
void    sort_three(t_node **stack);
void	sort_turk(t_node **a, t_node **b);

//stack initiation
int		has_invalid_syntax(char *c);
int 	has_duplicate(t_node *a, int n);
void	free_stack(t_node **stack);
void	init_stack_a(t_node **a, char **av);

//nodes initiation

//get & set utils
t_node  *get_last_node(t_node *stack);
t_node  *get_min(t_node *stack);
t_node  *get_max(t_node *stack);
t_node	*get_cheapest(t_node *stack);

void	set_index_n_median(t_node *stack);
void	set_target_a(t_node *a, t_node *b);
void	set_target_b(t_node *a, t_node *b);
void	set_pushcost_a(t_node *a, t_node *b);
void	set_cheapest(t_node *stack);

//stack utils
void	push_to_top(t_node **stack, t_node *top_node, char stack_name);
void	prep_stack_a(t_node *a, t_node *b);
void	prep_stack_b(t_node *a, t_node *b);
int     stack_len(t_node *stack);
bool    is_sorted(t_node *stack);

char	**split(char *s);
//handle errors
void	handle_invalid_syntax(t_node **a);
void	handle_overflow(t_node **a);
void	handle_duplicate(t_node **a);

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

//debug functions
void	print_stack(t_node *stack);
void	print_stack_reverse(t_node *stack);
#endif
