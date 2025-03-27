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

//instructions

//algo

#endif
