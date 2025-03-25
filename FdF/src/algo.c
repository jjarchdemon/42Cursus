/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:33:39 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/25 18:09:04 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	negative_slope(int x1, int y1, fdf *data, int color1, int color2)
{
	int		i;
	int		p;
	float	color_step;
	float	current_color;

	p = (2 * abs(data->side.dy)) - abs(data->side.dx);
	i = -1;
	// Calculate the color step for interpolation
	color_step = (float)(color2 - color1) / abs(data->side.dx);
	current_color = color1;
	while (++i < abs(data->side.dx))
	{
		if (data->side.dx > 0)
			x1++;
		else
			x1--;
		if (p < 0)
			p = p + (2 * abs(data->side.dy));
		else
		{
			if (data->side.dy > 0)
				y1++;
			else
				y1--;
			p = p + (2 * abs(data->side.dy)) - (2 * abs(data->side.dx));
		}
	// Draw the pixel with the interpolated color
		draw_pixel(data, x1, y1, (int)current_color);
		current_color += color_step;
	}
}

void	positive_slope(int x1, int y1, fdf *data, int color1, int color2)
{
	int	i;
	int	p;
	float	color_step;
	float	current_color;

	p = (2 * abs(data->side.dy)) - abs(data->side.dx);
	i = -1;
	// Calculate the color step for interpolation
	color_step = (float)(color2 - color1) / abs(data->side.dy);
	current_color = color1;
	while (++i < abs(data->side.dy))
	{
		if (data->side.dy > 0)
			y1++;
		else
			y1--;
		if (p < 0)
			p = p + (2 * abs(data->side.dx));
		else
		{
			if (data->side.dx > 0)
				x1++;
			else
				x1--;
			p = p + (2 * abs(data->side.dx)) - (2 * abs(data->side.dy));
		}
	// Draw the pixel with the interpolated color
		draw_pixel(data, x1, y1, (int)current_color);
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
