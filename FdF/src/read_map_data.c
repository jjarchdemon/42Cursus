/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:10 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 15:23:27 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	allocate_map_memory(t_fdf *data);
static int	fill_map_data(t_fdf *data, int fd);

t_fdf	*read_map_data(t_fdf *data, char *file)
{
    int	fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (free(data), NULL);
    if (get_size(file, &data->dmap.height, &data->dmap.width) == -1)
        return (free(data), close(fd), NULL);
    if (allocate_map_memory(data) == -1)
        return (free_map(data->dmap.input_map, data->dmap.height, data->dmap.width),
                free(data), close(fd), NULL);
    if (fill_map_data(data, fd) == -1)
        return (free_map(data->dmap.input_map, data->dmap.height, data->dmap.width),
                free(data), close(fd), NULL);
    data->dmap.max_z = find_max_z(data);
    data->dmap.min_z = find_min_z(data);
    close(fd);
    return (data);
}

static int	allocate_map_memory(t_fdf *data)
{
    int	i;
    int	j;

    data->dmap.input_map = malloc(sizeof(int **) * data->dmap.height);
    if (!data->dmap.input_map)
        return (-1);
    i = 0;
    while (i < data->dmap.height)
    {
        data->dmap.input_map[i] = malloc(sizeof(int *) * data->dmap.width);
        if (!data->dmap.input_map[i])
            return (free_map(data->dmap.input_map, i, data->dmap.width), -1);
        j = 0;
        while (j < data->dmap.width)
        {
            data->dmap.input_map[i][j] = malloc(sizeof(int) * 2);
            if (!data->dmap.input_map[i][j])
                return (free_map(data->dmap.input_map, i, data->dmap.width), -1);
            j++;
        }
        i++;
    }
    return (0);
}

static int	fill_map_data(t_fdf *data, int fd)
{
    int		i;
    char	*line;

    i = 0;
    line = get_next_line(fd);
    while (i < data->dmap.height && line)
    {
        if (!parse_map_line(data->dmap.input_map[i], data->dmap.width, line))
        {
            free(line);
            return (-1); // Return error if parsing fails.
        }
        free(line);
        line = get_next_line(fd);
        i++;
    }
    if (line)
        free(line);
    return (0);
}

int	*parse_map_line(int **row, int column_count, char *line_content)
{
    int		i;
    char	**number;
    char	**z_and_color;

    i = 0;
    number = ft_split(line_content, ' ');
    if (!number)
        return (NULL); // Return NULL if splitting fails.
    while (i < column_count)
    {
        z_and_color = ft_split(number[i], ',');
        if (!z_and_color)
        {
            free_arr(number);
            return (NULL); // Return NULL if splitting fails.
        }
        row[i][0] = ft_atoi(z_and_color[0]);
        if (z_and_color[1])
            row[i][1] = ft_atoi_base(z_and_color[1]);
        else
            row[i][1] = -1;
        free_arr(z_and_color);
        i++;
    }
    free_arr(number);
    return (*row);
}