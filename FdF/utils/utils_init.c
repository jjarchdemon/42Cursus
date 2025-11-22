/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:38:55 by jambatt           #+#    #+#             */
/*   Updated: 2025/11/22 13:15:54 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	if (!fdf)
		return;

	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->z_map = NULL;
	fdf->height = 0;
	fdf->width = 0;
	init_image(fdf);
	fdf->zoom = ZOOM_LEVEL;
	fdf->x_offset = WIDTH / 2;	//why?
	fdf->y_offset = HEIGHT / 2;	//why?
	fdf->angle = INITIAL_ANGLE;
}

void    init_image(t_fdf *fdf)
{
    if (!fdf)
        return;
    //Allocate the struct
    fdf->img = (t_img *)malloc(sizeof(t_img));
    if (!fdf->img)
        exit(1); // Proper exit
    
    //Setup the MLX image directly into new struct
    fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
    if (!fdf->img->img_ptr)
        exit(1);

    //Get the data address directly
    fdf->img->data_addr = mlx_get_data_addr(fdf->img->img_ptr, 
        &fdf->img->bits_per_pixel, 
        &fdf->img->size_line, 
        &fdf->img->endian);
}