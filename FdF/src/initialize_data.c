/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:44:25 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*initialize_data(void)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		print_memory_error(data);
	data->server = NULL;
	data->window = NULL;
	data->image = NULL;
	data->image_addr = NULL;
	data->map = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->map_dim_x = 0;
	data->map_dim_y = 0;
	data->scale = 1;
	data->max_x = INT_MIN;
	data->min_x = INT_MAX;
	data->max_y = INT_MIN;
	data->min_y = INT_MAX;
	data->offset_x = 0;
	data->offset_y = 0;
	return (data);
}
