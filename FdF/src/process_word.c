/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:46:14 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:46:16 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fill_with_values(t_point *point, char **values,
				int row_index, int col_index);

t_point	*process_word(char *word, int row_index, int col_index)
{
	int		flag;
	t_point	*p;
	char	**split;

	split = ft_split(word, ',');
	if (!split)
		return (NULL);
	p = malloc(sizeof (t_point));
	if (!p)
	{
		free(split);
		return (NULL);
	}
	flag = fill_with_values(p, split, row_index, col_index);
	if (flag)
	{
		free(p);
		p = NULL;
	}
	free_split_stuff(split);
	return (p);
}

static int	fill_with_values(t_point *point, char **values,
	int row_index, int col_index)
{
	if (!point || !values || !(*values))
		return (1);
	point->x = col_index;
	point->y = row_index;
	point->z = ft_atoi(*values);
	point->z_current = point->z;
	++values;
	if (*values)
		point->color = hex_atoi(*values);
	else
		point->color = (unsigned int) DEFAULT_COLOR;
	return (0);
}
