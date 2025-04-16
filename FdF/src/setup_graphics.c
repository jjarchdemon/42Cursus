/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_graphics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:35 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:44:39 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_graphics(t_data *data)
{
	data->mlx_server = mlx_init();
	if (!data->mlx_server)
		close_window(data);
	data->window = mlx_new_window(data->mlx_server, WIDTH, HEIGHT, "FDF");
	if (!data->window)
		close_window(data);
	data->img = mlx_new_image(data->mlx_server, WIDTH, HEIGHT);
	if (!data->img)
		close_window(data);
	data->img_addr = mlx_get_data_addr(data->img, &(data->bpp),
			&(data->line_length), &(data->endian));
}
