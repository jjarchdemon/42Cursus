/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:34:38 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 14:58:01 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//TODO change fn name to draw_pixel ?? , also order of params
void	draw_pixel(fdf *data, int x, int y, int color)
{
	char	*dst;
	int		pixel_offset;

	pixel_offset = y * data->size_line + x * (data->bpp / 8);
	if (x >= 0 && x < WIDTH && y >= 0 && y <= HEIGHT)
	{
		dst = data->address_data + pixel_offset;
		*(unsigned int *)dst = color;
	}
}
