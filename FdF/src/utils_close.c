/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:41:54 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/16 16:51:01 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Closes the application window and frees all allocated resources.
// This includes destroying the image, window, and mlx_server, as well as 
// freeing the map and data structure.
int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->img)
	{
		mlx_destroy_image(data->mlx_server, data->img);
		data->img = NULL;
	}
	if (data->window)
	{
		mlx_destroy_window(data->mlx_server, data->window);
		data->window = NULL;
	}
	if (data->mlx_server)
	{
		mlx_loop_end(data->mlx_server);
		mlx_destroy_display(data->mlx_server);
		free(data->mlx_server);
		data->mlx_server = NULL;
	}
	if (data->map)
		free_map(data->map);
	free(data);
	exit(0);
}

// Clears the image by setting all pixels to a specified color (BLACK).
// This is used to reset the image buffer before redrawing.
void	clear_image(t_data *data)
{
	char	*pixel;
	int		total_pixels;
	int		i;

	total_pixels = WIDTH * HEIGHT;
	i = 0;
	while (i < total_pixels)
	{
		pixel = data->img_addr + (i * ((data->bpp) / 8));
		*(unsigned int *)pixel = mlx_get_color_value(data->mlx_server, BLACK);
		i++;
	}
}
