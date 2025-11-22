/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:38:55 by jambatt           #+#    #+#             */
/*   Updated: 2025/11/22 11:53:04 by jambatt          ###   ########.fr       */
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
	fdf->img = NULL;
	fdf->zoom = 10;//TODO: ?
	fdf->x_offset = WIDTH / 2;//TODO: ?
	fdf->y_offset = HEIGHT / 2;//TODO: ?
	fdf->angle = 0.523599;	//TODO: ?
}