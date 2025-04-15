/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:43:14 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/15 12:40:13 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_points_arr(t_point **points, int index);

void	free_all(char *l, char **ss, t_point **p)
{
	free(l);
	free_split_array(ss);
	free(p);
	return ;
}

void	free_all_points_content(t_point ***map, int index)
{
	while (map && (index >= 0))
	{
		free_points_arr(map[index], get_array_length((void **)*map));
		index--;
	}
	return ;
}

void	free_map(t_point ***map)
{
	t_point	**line;
	int		line_index;
	int		map_index;

	if (!map)
		return ;
	map_index = 0;
	while (map[map_index])
	{
		line_index = 0;
		line = map[map_index];
		while (line[line_index])
		{
			free(line[line_index]);
			line_index++;
		}
		free(line);
		map_index++;
	}
	free(map);
	return ;
}

void	free_points_arr(t_point **points, int index)
{
	while (points && (index >= 0))
	{
		free(points[index]);
		index--;
	}
	free(points);
	return ;
}

void	free_split_array(char **split_stuff)
{
	char	**current_str;

	if (!split_stuff)
		return ;
	current_str = split_stuff;
	while (*current_str)
	{
		free(*current_str);
		current_str++;
	}
	free(split_stuff);
	return ;
}
