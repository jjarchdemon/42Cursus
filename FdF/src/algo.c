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

void	negative_slope(t_point start, t_point end, t_fdf *data)
{
    int		p = (2 * abs(data->side.dy)) - abs(data->side.dx);
    float	color_step = (float)(end.color - start.color) / abs(data->side.dx);
    float	current_color = start.color;

    while (start.x != end.x)
    {
        start.x += (data->side.dx > 0) ? 1 : -1;
        if (p >= 0)
        {
            start.y += (data->side.dy > 0) ? 1 : -1;
            p += (2 * abs(data->side.dy)) - (2 * abs(data->side.dx));
        }
        else
            p += 2 * abs(data->side.dy);
        draw_pixel(data, start.x, start.y, (int)current_color);
        current_color += color_step;
    }
}

void	positive_slope(t_point start, t_point end, t_fdf *data)
{
    int		p = (2 * abs(data->side.dx)) - abs(data->side.dy);
    float	color_step = (float)(end.color - start.color) / abs(data->side.dy);
    float	current_color = start.color;

    while (start.y != end.y)
    {
        start.y += (data->side.dy > 0) ? 1 : -1;
        if (p >= 0)
        {
            start.x += (data->side.dx > 0) ? 1 : -1;
            p += (2 * abs(data->side.dx)) - (2 * abs(data->side.dy));
        }
        else
            p += 2 * abs(data->side.dx);
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
