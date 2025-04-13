/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:34:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 13:42:34 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//4 bytes per pixel
void	set_pixels(t_fdf *data)
{
	ft_bzero(data->address_data, WIDTH * HEIGHT * 4);
	mlx_clear_window(data->mlx, data->wnd);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
}

void	draw_map(t_fdf *data)
{
	t_line_points	p;

	if (!data || !data->dmap.input_map)
		return ;
	p.x1 = 0;
	while (p.x1 < data->dmap.width)
	{
		p.y1 = 0;
		while (p.y1 < data->dmap.height)
		{
			if (p.x1 < data->dmap.width - 1)
				line(p.x1 + 1, p.y1, data, p);
			if (p.y1 < data->dmap.height - 1)
				line(p.x1, p.y1 + 1, data, p);
			p.y1++;
		}
		p.x1++;
	}
}

void	reproduce_pixels(t_line_points *p, t_fdf *data)
{
	t_map_scale	scaling;
	int			z_range;

	if (data->dmap.width > data->dmap.height)
		scaling.max_dimension = data->dmap.width;
	else
		scaling.max_dimension = data->dmap.height;
	z_range = data->dmap.max_z - data->dmap.min_z;
	if (z_range > scaling.max_dimension)
		scaling.max_dimension = z_range;
	scaling.x_scale = (WIDTH * 0.7) / scaling.max_dimension;
	scaling.y_scale = (HEIGHT * 0.7) / scaling.max_dimension;
	if (scaling.x_scale < scaling.y_scale)
		scaling.scale_factor = scaling.x_scale;
	else
		scaling.scale_factor = scaling.y_scale;
	p->x1 *= scaling.scale_factor;
	p->y1 *= scaling.scale_factor;
	p->x2 *= scaling.scale_factor;
	p->y2 *= scaling.scale_factor;
	data->side.z1 *= scaling.scale_factor + data->side.iso;
	data->side.z2 *= scaling.scale_factor + data->side.iso;
}

void	locate(t_line_points *p, t_fdf *data)
{
	p->x1 += (WIDTH / 2) - (data->dmap.width / 2);
	p->y1 += (HEIGHT / 10) - (data->dmap.height / 2);
	p->x2 += (WIDTH / 2) - (data->dmap.width / 2);
	p->y2 += (HEIGHT / 10) - (data->dmap.height / 2);
}
