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
	data->server = mlx_init();
	if (!data->server)
		close_window(data);
	data->window = mlx_new_window(data->server, WIDTH, HEIGHT, "FDF");
	if (!data->window)
		close_window(data);
	data->image = mlx_new_image(data->server, WIDTH, HEIGHT);
	if (!data->image)
		close_window(data);
	data->image_addr = mlx_get_data_addr(data->image, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
}
