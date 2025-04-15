/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:45 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/15 12:43:08 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_points_array(t_point ***points, char **split, int line_index,
				t_data *data);

t_point	**process_line(char *line, int line_index, t_data *data)
{
	int		line_length;
	t_point	**points;
	char	**split;

	if (!line)
		return (NULL);
	line = ft_strtrim(line, "\b\t\n\v\f\r ");
	if (!line)
		return (NULL);
	split = ft_split(line, ' ');
	line_length = get_array_length((void **)split);
	points = malloc((sizeof(t_point *)) *(line_length + 1));
	if (!split || !points)
	{
		free_all(line, split, points);
		return (NULL);
	}
	fill_points_array(&points, split, line_index, data);
	free_all(line, split, NULL);
	return (points);
}

static void	fill_points_array(t_point ***points, char **split, int line_index,
	t_data *data)
{
	int		index;
	t_point	*pt;

	index = 0;
	while (split[index])
	{
		if ((index + 1) > data->map_dim_x)
			data->map_dim_x = index + 1;
		pt = process_word(split[index], line_index, index);
		if (!pt)
		{
			free_points_arr(*points, --index);
			*points = NULL;
			return ;
		}
		(*points)[index] = pt;
		index++;
	}
	(*points)[index] = NULL;
	return ;
}
