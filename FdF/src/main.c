/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:16 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:45:18 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		print_usage_message();
	data = initialize_data();
	process_map(argv[1], data);
	transform_map(data);
	initialize_graphics(data);
	draw_map(data);
	mlx_key_hook(data->window, handle_key_events, data);
	mlx_hook(data->window, DestroyNotify, 0, close_window, data);
	mlx_loop(data->server);
}
