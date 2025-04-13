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

// Extracted logic for setting z and color values
static void	set_z_and_colors(t_fdf *data, t_line_points *p,
	int *color1, int *color2)
{
	data->side.z1 = data->dmap.input_map[p->y1][p->x1][0];
	data->side.z2 = data->dmap.input_map[p->y2][p->x2][0];
	*color1 = data->dmap.input_map[p->y1][p->x1][1];
	*color2 = data->dmap.input_map[p->y2][p->x2][1];
	if (*color1 == -1)
		*color1 = get_default_color(data->side.z1, data);
	if (*color2 == -1)
		*color2 = get_default_color(data->side.z2, data);
}

// Extracted logic for boundary check
static int	is_out_of_bounds(int x1, int x2, int y1, int y2)
{
	return ((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH)
		|| (y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT));
}

// Extracted slope logic
static void	draw_slope(t_line_points p, t_fdf *data, int color1, int color2)
{
	t_point	start;
	t_point	end;

	start.x = p.x1;
	start.y = p.y1;
	start.color = color1;
	end.x = p.x2;
	end.y = p.y2;
	end.color = color2;
	if (abs(data->side.dx) > abs(data->side.dy))
		negative_slope(start, end, data);
	else
		positive_slope(start, end, data);
}

void	line(int x2, int y2, t_fdf *data, t_line_points p)
{
	int	color1;
	int	color2;

	p.x2 = x2;
	p.y2 = y2;
	set_z_and_colors(data, &p, &color1, &color2);
	reproduce_pixels(&p, data);
	locate(&p, data);
	isometric(&p.x1, &p.y1, data->side.z1);
	isometric(&p.x2, &p.y2, data->side.z2);
	if (is_out_of_bounds(p.x1, p.x2, p.y1, p.y2))
		return ;
	data->side.dx = p.x2 - p.x1;
	data->side.dy = p.y2 - p.y1;
	draw_slope(p, data, color1, color2);
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
