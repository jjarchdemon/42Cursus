/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:10 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 15:22:53 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*read_map_data(fdf *data, char **file)//readfile(... char **file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file[1], O_RDONLY);
	if (fd == -1)
		return (free(data), NULL);
	if (get_size(&data->map.height, file[1], &data->map.width) == 1)
		return (free(data), NULL);
	data->map.render_map = malloc(sizeof(int *) * (data->map.height + 1));
	while (i < data->map.height)
		data->map.render_map[i++] = malloc(sizeof(int) * data->map.width);
	i = 0;
	line = get_next_line(fd);
	while (i < data->map.height && line)
	{
		parse_map_line(data->map.render_map[i++], data->map.width, line);
		line = get_next_line(fd);
	}
	data->map.render_map[data->map.height] = NULL;
	close(fd);
	return (data);
}

int	get_size(int *height, char *file, int *width)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	line = get_next_line(fd);
	*width = count_words(line, ' ');//TODO WTF
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	*height = i;
	close(fd);
	return (i);
}

int	*parse_map_line(int *map_line, int width, char *line)//fill_map
{
	int		i;
	char	**number;

	i = 0;
	number = ft_split(line, ' ');
	while (i < width)
	{
		map_line[i] = ft_atoi(number[i]);
		i++;
	}
	free_arr(number);
	return (map_line);
}
