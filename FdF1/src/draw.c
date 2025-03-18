/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:34:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 15:10:20 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixels(fdf *data)
{
	ft_bzero(data->address_data, WIDTH * HEIGHT * 4);
	mlx_clear_window(data->mlx, data->wnd);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
}

void	draw_map(fdf *data)
{
	line_points	p;

	if (!data || !data->map.render_map)
		return ;
	p.x1 = 0;
	while (p.x1 < data->map.width)
	{
		p.y1 = 0;
		while (p.y1 < data->map.height)
		{
			if (p.x1 < data->map.width - 1)
				line(p.x1 + 1, p.y1, data, p);
			if (p.y1 < data->map.height - 1)
				line(p.x1, p.y1 + 1, data, p);
			p.y1 += 1;
		}
		p.x1 += 1;
	}
}

void	line(int x2, int y2, fdf *data, line_points p)
{
	p.x2 = x2;
	p.y2 = y2;
	data->side.z1 = data->map.render_map[p.y1][p.x1];
	data->side.z2 = data->map.render_map[p.y2][p.x2];
	reproduce_pixels(&p, data);
	locate(&p, data);
	isometric(&p.x1, &p.y1, data->side.z1);
	isometric(&p.x2, &p.y2, data->side.z2);
	if ((p.x1 < 0 && p.x2 < 0) || (p.x1 > WIDTH && p.x2 > WIDTH) || (p.y1 < 0 && p.y2 < 0) || (p.y1 > HEIGHT && p.y2 > HEIGHT))
		return ;
	data->side.dx = p.x2 - p.x1;
	data->side.dy = p.y2 - p.y1;
	if (abs(data->side.dx) > abs(data->side.dy))
		negative_slope(p.x1, p.y1, data);
	else
		positive_slope(p.x1, p.y1, data);
}

void	reproduce_pixels(line_points *p, fdf *data)
{
	map_scale	scaling;

	if (data->map.width > data->map.height)
		scaling.max_dimension = data->map.width;
	else
		scaling.max_dimension = data->map.height;
	scaling.x_scale = (WIDTH * 0.8) / scaling.max_dimension;
	scaling.y_scale = (HEIGHT * 0.8) / scaling.max_dimension;
	if (scaling.x_scale < scaling.y_scale)
		scaling.scale_factor = scaling.x_scale;
	else
		scaling.scale_factor = scaling.y_scale;
	if (scaling.scale_factor > 10)
		scaling.scale_factor = 10;
	p->x1 *= scaling.scale_factor + data->window.zoom;
	p->y1 *= scaling.scale_factor + data->window.zoom;
	p->x2 *= scaling.scale_factor + data->window.zoom;
	p->y2 *= scaling.scale_factor + data->window.zoom;
	data->side.z1 *= scaling.scale_factor + data->window.zoom + data->side.iso;
	data->side.z2 *= scaling.scale_factor + data->window.zoom + data->side.iso;
}

void	locate(line_points *p, fdf *data)
{
	view_control	_;

	_.shift_down = data->window.shift_down;
	_.shift_up = data->window.shift_up;
	_.shift_left = data->window.shift_left;
	_.shift_right = data->window.shift_right;
	_.zoom = data->window.zoom;
	p->x1 += (WIDTH / 2) - (data->map.width * _.zoom / 2) + _.shift_left;
	p->y1 += (HEIGHT / 8) - (data->map.height * _.zoom / 2) + _.shift_up;
	p->x2 += (WIDTH / 2) - (data->map.width * _.zoom / 2) + _.shift_right;
	p->y2 += (HEIGHT / 8) - (data->map.height * _.zoom / 2) + _.shift_down;
}
