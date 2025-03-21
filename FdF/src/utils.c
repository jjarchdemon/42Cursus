/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:22 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 15:59:32 by jambatt          ###   ########.fr       */
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
		free_map(data->map.input_map);
		free(data);
	}
	exit(0);
	return (0); //it doesnt reach here
}

/*
int	close_window(fdf *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->wnd)
		mlx_destroy_window(data->mlx, data->wnd);
	if (data->mlx)
	{
//		mlx_loop_end(data->mlx);  commented out for mac
	//	mlx_destroy_display(data->mlx);	commented out for mac
		free(data->mlx);
	}
	if (data->map.input_map)
		free_map(data->map.input_map);
	ft_printf("Project exited\n");
	if (data)
		free(data);
	exit(0);
}
*/

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

void	free_map(int **arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
