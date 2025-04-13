/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:33:39 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 14:00:09 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	update_negative_slope(t_point *start, t_fdf *data, int *p)
{
	if (*p >= 0)
	{
		if (data->side.dy > 0)
			start->y += 1;
		else
			start->y -= 1;
		*p += (2 * abs(data->side.dy)) - (2 * abs(data->side.dx));
	}
	else
		*p += 2 * abs(data->side.dy);
}

void	negative_slope(t_point start, t_point end, t_fdf *data)
{
	int		p;
	float	color_step;
	float	current_color;

	p = (2 * abs(data->side.dy)) - abs(data->side.dx);
	color_step = (float)(end.color - start.color) / abs(data->side.dx);
	current_color = start.color;
	while (start.x != end.x)
	{
		if (data->side.dx > 0)
			start.x += 1;
		else
			start.x -= 1;
		update_negative_slope(&start, data, &p);
		draw_pixel(data, start.x, start.y, (int)current_color);
		current_color += color_step;
	}
}

static void	update_positive_slope(t_point *start, t_fdf *data, int *p)
{
	if (*p >= 0)
	{
		if (data->side.dx > 0)
			start->x += 1;
		else
			start->x -= 1;
		*p += (2 * abs(data->side.dx)) - (2 * abs(data->side.dy));
	}
	else
		*p += 2 * abs(data->side.dx);
}

void	positive_slope(t_point start, t_point end, t_fdf *data)
{
	int		p;
	float	color_step;
	float	current_color;

	p = (2 * abs(data->side.dx)) - abs(data->side.dy);
	color_step = (float)(end.color - start.color) / abs(data->side.dy);
	current_color = start.color;
	while (start.y != end.y)
	{
		if (data->side.dy > 0)
			start.y += 1;
		else
			start.y -= 1;
		update_positive_slope(&start, data, &p);
		draw_pixel(data, start.x, start.y, (int)current_color);
		current_color += color_step;
	}
}

void	isometric(int *x, int *y, int z)
{
	int		tmp_x;
	int		tmp_y;
	float	angle;

	tmp_x = *x;
	tmp_y = *y;
	angle = 0.523599;
	*x = (tmp_x - tmp_y) * cos(angle);
	*y = (tmp_x + tmp_y) * sin(angle) - z;
}