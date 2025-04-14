/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:41:54 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:41:58 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->image)
	{
		mlx_destroy_image(data->server, data->image);
		data->image = NULL;
	}
	if (data->window)
	{
		mlx_destroy_window(data->server, data->window);
		data->window = NULL;
	}
	if (data->server)
	{
		mlx_loop_end(data->server);
		mlx_destroy_display(data->server);
		free(data->server);
		data->server = NULL;
	}
	if (data->map)
		free_map(data->map);
	free(data);
	exit(0);
}
