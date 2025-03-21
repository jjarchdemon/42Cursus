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
	ft_bzero(data->address_data, WIDTH * HEIGHT * 4);//4  bcoz 4 bytes per pixel
	mlx_clear_window(data->mlx, data->wnd);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
}

void	draw_map(fdf *data)
{
	line_points	p;

	if (!data || !data->map.input_map)
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
			p.y1++;
		}
		p.x1++;
	}
}

void	line(int x2, int y2, fdf *data, line_points p)
{
	p.x2 = x2;
	p.y2 = y2;
	data->side.z1 = data->map.input_map[p.y1][p.x1];
	data->side.z2 = data->map.input_map[p.y2][p.x2];
	reproduce_pixels(&p, data);
	locate(&p, data);
	isometric(&p.x1, &p.y1, data->side.z1);
	isometric(&p.x2, &p.y2, data->side.z2);
	if ((p.x1 < 0 && p.x2 < 0) || (p.x1 > WIDTH && p.x2 > WIDTH)
		|| (p.y1 < 0 && p.y2 < 0) || (p.y1 > HEIGHT && p.y2 > HEIGHT))
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
	int			z_range;

	if (data->map.width > data->map.height)
		scaling.max_dimension = data->map.width;
	else
		scaling.max_dimension = data->map.height;
	z_range = data->map.max_z - data->map.min_z;
    if (z_range > scaling.max_dimension)
        scaling.max_dimension = z_range;
	scaling.x_scale = (WIDTH * 0.7) / scaling.max_dimension;
	scaling.y_scale = (HEIGHT * 0.7) / scaling.max_dimension;
	if (scaling.x_scale < scaling.y_scale)
		scaling.scale_factor = scaling.x_scale;
	else
		scaling.scale_factor = scaling.y_scale;

	//data->scale_factor = scaling.scale_factor;
	//if (scaling.scale_factor > 15)
		//scaling.scale_factor = 15;
	p->x1 *= scaling.scale_factor;
	p->y1 *= scaling.scale_factor;
	p->x2 *= scaling.scale_factor;
	p->y2 *= scaling.scale_factor;

	data->side.z1 *= scaling.scale_factor + data->side.iso;
	data->side.z2 *= scaling.scale_factor + data->side.iso;
}

void	locate(line_points *p, fdf *data)
{
	/*
	p->x1 += (WIDTH / 2) - ((data->map.width * data->scale_factor) / 2);
    p->y1 += (HEIGHT / 2) - ((data->map.height * data->scale_factor) / 2);
    p->x2 += (WIDTH / 2) - ((data->map.width * data->scale_factor) / 2);
    p->y2 += (HEIGHT / 2) - ((data->map.height * data->scale_factor) / 2);
	*/
	p->x1 += (WIDTH / 2) - (data->map.width / 2) ;
	p->y1 += (HEIGHT / 10) - (data->map.height / 2) ;
	p->x2 += (WIDTH / 2) - (data->map.width / 2) ;
	p->y2 += (HEIGHT / 10) - (data->map.height / 2) ;
}
