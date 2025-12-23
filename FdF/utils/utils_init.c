/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:38:55 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 14:50:55 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	if (!fdf)
		return;

	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->z_map = NULL;			//TODO: need to allocate thru parsing
	fdf->height = 0;
	fdf->width = 0;
	init_img(fdf);
	fdf->zoom = ZOOM_LEVEL;     //TODO: understand
	fdf->x_offset = WIDTH / 2;  //TODO: understand
	fdf->y_offset = HEIGHT / 2; //TODO: understand
	fdf->angle = INITIAL_ANGLE; //TODO: understand
}

void    init_img(t_fdf *fdf)
{
    if (!fdf)
        return;
    fdf->img = (t_img *)malloc(sizeof(t_img));
    if (!fdf->img)
        exit(1); //TODO: error handling
	create_blank_image(fdf);
}
