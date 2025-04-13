/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:24:24 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 13:51:23 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// main mlx function
int	my_mlx(t_fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_map(data->dmap.input_map, data->dmap.height,
				data->dmap.width), free(data), 1);
	data->wnd = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	if (!data->wnd)
		return (clean_close(data), 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (clean_close(data), 1);
	data->address_data = mlx_get_data_addr(data->img, &data->bpp,
			&data->size_line, &data->endian);
	if (!data->address_data)
		return (clean_close(data), 1);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
	return (0);
}

// 17 - handles close button
// 2 - handles keypress
void	my_hook(t_fdf *data)
{
	mlx_hook(data->wnd, 17, 0, clean_close, data);
	mlx_hook(data->wnd, 2, 0, handle_keypress, data);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2)
		return (ft_printf("./t_fdf [dmap]\n"), 1);
	data = create_fdf_data();
	if (!data)
		return (1);
	data = read_map_data(data, av[1]);
	if (!data)
		return (1);
	if (my_mlx(data))
		return (1);
	set_pixels(data);
	my_hook(data);
	mlx_loop(data->mlx);
	return (0);
}
