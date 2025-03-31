/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:09:11 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/25 17:09:14 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	//t_node	*b;

	a = NULL;
	//b = NULL;
	
	// if (ac == 1 || (ac == 2 && (!av[1][0] || !ft_strlen(ft_strtrim(av[1], ' ')))))
	if (ac == 1 || (ac ==2 && !av[1][0]))
		return (1);	//error message
	else if (ac == 2)
		av = split(av[1]);
	if (!av || !*av)
		return (1);	//error message
	init_stack_a(&a, av + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_3stack(&a);
		else
			ft_printf("turkish algo");//turkish algo
	}
	free_stack(&a);
	return (0);
}