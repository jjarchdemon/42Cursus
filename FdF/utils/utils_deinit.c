/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_deinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:02:00 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 11:39:32 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// deinit for mlx pointers
#ifdef __linux__

void    deinit_mlx(t_fdf *fdf)
{
	if (!fdf)
		return;
	if (fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	
	if (fdf->mlx_ptr)
	{
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
}

#elif __APPLE__

void    deinit_mlx(t_fdf *fdf)
{
	if (!fdf)
		return;
	if (fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->mlx_ptr = NULL;
}
#endif

void    deinit_img(t_fdf *fdf)
{
	if (!fdf)
		return;
	if (fdf->img)
	{
		if (fdf->img->img_ptr)
			mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
		free(fdf->img);
	}
}
void    deinit_map(t_fdf *fdf)
{
	if (!fdf)
		return;
	if (fdf->z_map)
		free(fdf->z_map);
}

void    deinit_fdf(t_fdf *fdf)
{
	deinit_img(fdf);
	deinit_map(fdf);
	deinit_mlx(fdf);
	free(fdf);
}