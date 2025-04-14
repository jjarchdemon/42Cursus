/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:44 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:42:48 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_first_point(t_line *line, t_point *point);
static void	fill_second_point(t_line *line, t_point *point);
static void	loop_through_row(t_data *data, t_point ***map);

void	draw_map(t_data *data)
{
	t_point	***map;

	map = data->map;
	clear_image(data);
	while (*map)
	{
		loop_through_row(data, map);
		++map;
	}
	mlx_clear_window(data->server, data->window);
	mlx_put_image_to_window(data->server, data->window, data->image, 0, 0);
}

static void	loop_through_row(t_data *data, t_point ***map)
{
	int		col_index;
	t_line	line;
	t_point	**row;

	col_index = 0;
	row = *map;
	while (*row)
	{
		fill_first_point(&line, *row);
		if (*(row + 1))
		{
			fill_second_point(&line, *(row + 1));
			draw_line(data, line);
		}
		if (*(map + 1) && get_point_array_length(*(map + 1)) > col_index)
		{
			fill_second_point(&line, (*(map + 1))[col_index]);
			draw_line(data, line);
		}
		++row;
		++col_index;
	}
}

static void	fill_first_point(t_line *line, t_point *point)
{
	line->x0 = point->x_projected;
	line->y0 = point->y_projected;
	line->color_start = point->color;
	return ;
}

static void	fill_second_point(t_line *line, t_point *point)
{
	line->x1 = point->x_projected;
	line->y1 = point->y_projected;
	line->color_end = point->color;
	return ;
}
