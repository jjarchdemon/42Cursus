/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:24:24 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 15:29:24 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// main mlx function
int	my_mlx(fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_map(data->map.render_map), free(data), 1);
	data->wnd = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	if (!data->wnd)
		return (ft_close(data), 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (ft_close(data), 1);
	data->address_data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
	if (!data->address_data)
		return (ft_close(data), 1);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
	return (0);
}

// keyboard and mouse handler
void	my_hook(fdf *data)
{
	mlx_hook(data->wnd, 17, 0, close_window, data);// Handles close button
	mlx_hook(data->wnd, 2, 1L << 0, handle_keypress, data);// Handles key press
}

int	main(int ac, char **av)
{
	fdf	*data;

	data = NULL;
	if (ac != 2)
		return (ft_printf("./fdf [map]\n"), 1);
	data = create_fdf_data();
	if (!data)
		return (1);
	data = read_map_data(data, av);
	if (!data)
		return (1);
	if (my_mlx(data))
		return (1);
	set_pixels(data);
	my_hook(data);
	mlx_loop(data->mlx);
	return (0);
}
