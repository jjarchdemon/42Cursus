/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:44 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/16 15:27:07 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_first_point(t_line *line, t_point *point);
static void	set_second_point(t_line *line, t_point *point);
static void	loop_through_row(t_data *data, t_point ***map);

// Function to draw the map by iterating through all rows and columns of map.
// Clears the image, draws the map, and updates the window with the new image.
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
	mlx_clear_window(data->mlx_server, data->window);
	mlx_put_image_to_window(data->mlx_server, data->window, data->img, 0, 0);
}

// Loops through a single row of map and draws lines between points in row
// and between the current row and the next row if applicable.
static void	loop_through_row(t_data *data, t_point ***map)
{
	int		col_index;
	t_line	line;
	t_point	**row;

	col_index = 0;
	row = *map;
	while (*row)
	{
		set_first_point(&line, *row);
		if (*(row + 1))
		{
			set_second_point(&line, *(row + 1));
			draw_line(data, line);
		}
		if (*(map + 1) && get_array_length((void **)*(map + 1)) > col_index)
		{
			set_second_point(&line, (*(map + 1))[col_index]);
			draw_line(data, line);
		}
		++row;
		++col_index;
	}
}

// Sets the starting point of a line using the projected coordinates
// and color of the given point.
static void	set_first_point(t_line *line, t_point *point)
{
	line->x0 = point->x_projected;
	line->y0 = point->y_projected;
	line->color_start = point->color;
	return ;
}

// Sets the starting point of a line using the projected coordinates
// and color of the given point.
static void	set_second_point(t_line *line, t_point *point)
{
	line->x1 = point->x_projected;
	line->y1 = point->y_projected;
	line->color_end = point->color;
	return ;
}
