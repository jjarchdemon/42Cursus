/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/16 12:35:05 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * - create_data_struct: Allocates memory for a `t_data` structure and
 *   initializes its fields to default values. This structure holds
 *   information about the rendering environment, map dimensions, and
 *   transformation parameters.
 */
t_data	*create_data_struct(void)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		allocation_error(data);
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
