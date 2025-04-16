/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:46:14 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/16 12:34:09 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_t_point_values(t_point *point, char **values, int row_index,
				int col_index);

/*
 * - process_word: Parses a word from the input map, splits it into components
 *   (coordinates and optional color), and initializes a `t_point` structure.
 */
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
	flag = set_t_point_values(p, split, row_index, col_index);
	if (flag)
	{
		free(p);
		p = NULL;
	}
	free_split_array(split);
	return (p);
}

static int	set_t_point_values(t_point *point, char **values,
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
		point->color = htoi(*values);
	else
		point->color = (unsigned int) DEFAULT_COLOR;
	return (0);
}
