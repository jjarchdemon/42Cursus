/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:19:00 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 14:56:34 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//TODO: understand this
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		y_offset;
	int		x_offset;

	y_offset = y * img->size_line;
	x_offset = x * (img->bits_per_pixel / 8);
	dst = img->data_addr + x_offset + y_offset;
	*(unsigned int *)dst = color;
}

void	create_blank_image(t_fdf *fdf)
{
	t_img	*img;

	img = fdf->img;
	img->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	if (!img->img_ptr)
		exit(1);//TODO:handle error
	img->data_addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
		&img->size_line, &img->endian);
}
