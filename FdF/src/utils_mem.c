/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:53 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 14:10:57 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    free_arr(char **str)
{
        int     i;

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

void    free_map(int ***arr, int height, int width)
{
        int     i;
        int     j;

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


int     clean_close(t_fdf *data)
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
