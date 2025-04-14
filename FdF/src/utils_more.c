/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:43:26 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 11:43:29 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	find_max_z(t_fdf *data)
{
	int	max_z;
	int	i;
	int	j;

	if (!data || !data->dmap.input_map || data->dmap.height == 0
		|| data->dmap.width == 0)
		return (0);
	max_z = data->dmap.input_map[0][0][0];
	i = 0;
	while (i < data->dmap.height)
	{
		j = 0;
		while (j < data->dmap.width)
		{
			if (data->dmap.input_map[i][j][0] > max_z)
				max_z = data->dmap.input_map[i][j][0];
			j++;
		}
		i++;
	}
	return (max_z);
}

int	find_min_z(t_fdf *data)
{
	int	min_z;
	int	i;
	int	j;

	if (!data || !data->dmap.input_map || data->dmap.height == 0
		|| data->dmap.width == 0)
		return (0);
	min_z = data->dmap.input_map[0][0][0];
	i = 0;
	while (i < data->dmap.height)
	{
		j = 0;
		while (j < data->dmap.width)
		{
			if (data->dmap.input_map[i][j][0] < min_z)
				min_z = data->dmap.input_map[i][j][0];
			j++;
		}
		i++;
	}
	return (min_z);
}

static int	handle_line_and_width(char *line, int *width, int fd)
{
	if (!line)
	{
		close(fd);
		return (-1);
	}
	*width = count_words(line, ' ');
	if (*width == 0)
	{
		free(line);
		close(fd);
		return (-1);
	}
	free(line);
	return (0);
}

int	get_size(char *file, int *height, int *width)
{
	int		fd;
	char	*line;

	if (!file || !height || !width)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (handle_line_and_width(line, width, fd) == -1)
		return (-1);
	*height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		(*height)++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
