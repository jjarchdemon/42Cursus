/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 14:01:56 by jambatt          ###   ########.fr       */
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
	data->data_map.input_map = NULL;
	return (data);
}

int	clean_close(t_fdf *data)
{
	if (data)
	{
		if (data->mlx)
		{
			if (data->wnd)
				mlx_destroy_window(data->mlx, data->wnd);
			if (data->img)
				mlx_destroy_image(data->mlx, data->img);
			free(data->mlx);
		}
		free_map(data->data_map.input_map, data->data_map.height,
			data->data_map.width);
		free(data);
	}
	exit(0);
	return (0);
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_map(int ***arr, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	if (!arr)
		return ;
	while (i < height)
	{
		if (arr[i])
		{
			j = 0;
			while (j < width)
			{
				free(arr[i][j]);
				j++;
			}
			free(arr[i]);
		}
		i++;
	}
	free(arr);
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
