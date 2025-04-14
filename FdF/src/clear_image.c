/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:41:30 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:41:40 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_data *data)
{
	char	*pixel;
	int		x;
	int		y;

	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			pixel = data->image_addr + (y * data->line_length)
				+ (x * ((data->bits_per_pixel) / 8));
			*(unsigned int *)pixel = mlx_get_color_value(data->server, BLACK);
			++x;
		}
		++y;
	}
}
