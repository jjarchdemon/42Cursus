/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:46:37 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/15 12:25:16 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	center_map(t_data *data);
static void	project_point(t_point *point);
static void	scale_map(t_data *data, t_point *point);
static void	set_max_min_values(t_data *data, t_point *point);

void	transform_map(t_data *data)
{
	t_point	**line;
	t_point	***map;
	t_point	*point;

	map = data->map;
	while (*map)
	{
		line = *map;
		while (*line)
		{
			point = *line;
			scale_map(data, point);
			project_point(point);
			set_max_min_values(data, point);
			line++;
		}
		map++;
	}
	data->offset_x = (WIDTH / 2) - ((data->min_x + data->max_x) / 2);
	data->offset_y = (HEIGHT / 2) - ((data->min_y + data->max_y) / 2);
	center_map(data);
}

static void	center_map(t_data *data)
{
	t_point	**line;
	t_point	***map;
	t_point	*point;

	map = data->map;
	while (*map)
	{
		line = *map;
		while (*line)
		{
			point = *line;
			point->x_projected += data->offset_x;
			point->y_projected += data->offset_y;
			line++;
		}
		map++;
	}
}

static void	project_point(t_point *point)
{
	point->x_projected = (point->x - point->y) * cos(ANGLE);
	point->y_projected = ((point->x + point->y) * sin(ANGLE)
			- point->z_current);
	return ;
}

static void	scale_map(t_data *data, t_point *point)
{
	point->x = point->x * data->scale;
	point->y = point->y * data->scale;
	return ;
}

static void	set_max_min_values(t_data *data, t_point *point)
{
	if (point->x_projected > data->max_x)
		data->max_x = point->x_projected;
	if (point->x_projected < data->min_x)
		data->min_x = point->x_projected;
	if (point->y_projected > data->max_y)
		data->max_y = point->y_projected;
	if (point->y_projected < data->min_y)
		data->min_y = point->y_projected;
	return ;
}
