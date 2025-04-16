/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:41:54 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/16 15:40:16 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Closes the application window and frees all allocated resources.
// This includes destroying the image, window, and server, as well as 
// freeing the map and data structure.
int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->image)
	{
		mlx_destroy_image(data->server, data->image); //uncomment for linux
		data->image = NULL;
	}
	if (data->window)
	{
		mlx_destroy_window(data->server, data->window);
		data->window = NULL;
	}
	if (data->server)
	{
		mlx_loop_end(data->server); //uncomment for linux
		mlx_destroy_display(data->server); //uncomment for linux
		free(data->server);
		data->server = NULL;
	}
	if (data->map)
		free_map(data->map);
	free(data);
	exit(0);
}
/*
void	clear_image(t_data *data)
{
	char	*pixel;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = data->image_addr + (y * data->line_length)
				+ (x * ((data->bits_per_pixel) / 8));
			*(unsigned int *)pixel = mlx_get_color_value(data->server, BLACK);
			x++;
		}
		y++;
	}
}
*/

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
		pixel = data->image_addr + (i * ((data->bits_per_pixel) / 8));
		*(unsigned int *)pixel = mlx_get_color_value(data->server, BLACK);
		i++;
	}
}