/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 14:10:52 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*create_fdf_data(void)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	data->side.iso = 0;
	data->mlx = NULL;
	data->wnd = NULL;
	data->img = NULL;
	data->address_data = NULL;
	data->dmap.input_map = NULL;
	return (data);
}

static int	get_hex_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (c - 'A' + 10);
}

int	ft_atoi_base(const char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result = (result << 4) + get_hex_value(*str);
		str++;
	}
	return (result);
}
