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
    p.start.x = 0;
    while (p.start.x < data->dmap.width)
    {
        p.start.y = 0;
        while (p.start.y < data->dmap.height)
        {
            if (p.start.x < data->dmap.width - 1)
            {
                p.end.x = p.start.x + 1;
                p.end.y = p.start.y;
                line(p.end.x, p.end.y, data, p);
            }
            if (p.start.y < data->dmap.height - 1)
            {
                p.end.x = p.start.x;
                p.end.y = p.start.y + 1;
                line(p.end.x, p.end.y, data, p);
            }
            p.start.y++;
        }
        p.start.x++;
    }
}

void	reproduce_pixels(t_line_points *p, t_fdf *data)
{
    int	z_range;

    if (data->dmap.width > data->dmap.height)
        data->dmap.scale_factor = data->dmap.width;
    else
        data->dmap.scale_factor = data->dmap.height;
    z_range = data->dmap.max_z - data->dmap.min_z;
    if (z_range > data->dmap.scale_factor)
        data->dmap.scale_factor = z_range;
    data->dmap.x_scale = (WIDTH * 0.7) / data->dmap.scale_factor;
    data->dmap.y_scale = (HEIGHT * 0.7) / data->dmap.scale_factor;
    if (data->dmap.x_scale < data->dmap.y_scale)
        data->dmap.scale_factor = data->dmap.x_scale;
    else
        data->dmap.scale_factor = data->dmap.y_scale;
    p->start.x *= data->dmap.scale_factor;
    p->start.y *= data->dmap.scale_factor;
    p->end.x *= data->dmap.scale_factor;
    p->end.y *= data->dmap.scale_factor;
    data->side.z1 *= data->dmap.scale_factor + data->is_iso;
    data->side.z2 *= data->dmap.scale_factor + data->is_iso;
}

void	locate(t_line_points *p, t_fdf *data)
{
    p->start.x += (WIDTH / 2) - (data->dmap.width / 2);
    p->start.y += (HEIGHT / 10) - (data->dmap.height / 2);
    p->end.x += (WIDTH / 2) - (data->dmap.width / 2);
    p->end.y += (HEIGHT / 10) - (data->dmap.height / 2);
}
