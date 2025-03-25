/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/25 18:32:12 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*create_fdf_data(void)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		return (NULL);
	data->side.iso = 0;
	//data->window.offset_x = (WIDTH / 10);
	//data->window.offset_y = (HEIGHT / 3);
	//data->window.zoom = 0;
	data->mlx = NULL;
	data->wnd = NULL;
	data->img = NULL;
	data->address_data = NULL;
	data->map.input_map = NULL;
	return (data);
}

int	clean_close(fdf *data)
{
	if (data)
	{
		if (data->mlx)
		{
			if (data->wnd)
				mlx_destroy_window(data->mlx, data->wnd);
			if (data->img)
				mlx_destroy_image(data->mlx, data->img);
			//if (data->mlx)	commented out for mac
			//	mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free_map(data->map.input_map, data->map.height, data->map.width);
		free(data);
	}
	exit(0);
	return (0); //it doesnt reach here
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
	// Iterate over the height (rows)
	while (i < height)
	{
		if (arr[i])
		{
			j = 0;
			// Iterate over the width (columns)
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
