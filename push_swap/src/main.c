/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:09:11 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/07 14:41:13 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	handle_input(int ac, char **av, t_node **a)
{
    char	**temp;

    if (ac == 2)
    {
        temp = ft_split(av[1], ' ');
        init_stack_a(a, temp);
        free_split(temp);
    }
    else
        init_stack_a(a, av + 1);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_input(ac, av, &a);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_turk(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
