/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:16 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/15 12:04:52 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_horizontal_line(t_data *data, t_line l);
static void	draw_vertical_line(t_data *data, t_line l);
static void	put_pixel_in_image(t_data *data, int x, int y, int color);
static void	set_differences(t_line *line);

void	draw_line(t_data *data, t_line l)
{
	if (abs(l.x1 - l.x0) > abs(l.y1 - l.y0))
	{
		if (l.x0 > l.x1)
			swap_line_values(&l);
		set_differences(&l);
		draw_horizontal_line(data, l);
	}
	else
	{
		if (l.y0 > l.y1)
			swap_line_values(&l);
		set_differences(&l);
		draw_vertical_line(data, l);
	}
}

static void	draw_horizontal_line(t_data *data, t_line l)
{
	int	dir;
	int	index;
	int	p;
	int	y;

	dir = 1;
	if (l.dy < 0)
		dir = -1;
	l.dy *= dir;
	if (l.dx == 0)
		return ;
	index = 0;
	p = 2 * l.dy - l.dx;
	y = l.y0;
	while (index < (l.dx + 1))
	{
		put_pixel_in_image(data, l.x0 + index, y,
			blend_color(l.color_start, l.color_end,
				((double)index) / l.dx));
		update_horizontal_values(&l, &p, &y, dir);
		index++;
	}
}

static void	draw_vertical_line(t_data *data, t_line l)
{
	int	dir;
	int	index;
	int	p;
	int	x;

	dir = 1;
	if (l.dx < 0)
		dir = -1;
	l.dx *= dir;
	if (l.dy == 0)
		return ;
	index = 0;
	p = 2 * l.dx - l.dy;
	x = l.x0;
	while (index < (l.dy + 1))
	{
		put_pixel_in_image(data, x, l.y0 + index,
			blend_color(l.color_start, l.color_end,
				((double)index) / l.dy));
		update_vertical_values(&l, &p, &x, dir);
		index++;
	}
}

static void	put_pixel_in_image(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = data->image_addr + (y * data->line_length)
			+ (x * ((data->bits_per_pixel) / 8));
		*(unsigned int *)pixel = mlx_get_color_value(data->server, color);
	}
	return ;
}

static void	set_differences(t_line *line)
{
	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	return ;
}
