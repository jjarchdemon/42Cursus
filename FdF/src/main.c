/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:16 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/15 11:39:06 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		argument_error();
	data = initialize_data();
	load_map_data(av[1], data);
	transform_map(data);
	initialize_graphics(data);
	draw_map(data);
	mlx_key_hook(data->window, handle_key_events, data);
	mlx_hook(data->window, DestroyNotify, 0, close_window, data);// uncomment for linux
	mlx_loop(data->server);
}
