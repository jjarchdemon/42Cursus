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

fdf	*read_map_data(fdf *data, char *file)//readfile(... char **file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(data), NULL);
	if (get_size(file, &data->map.height, &data->map.width) == 1) //enough?
		return (free(data), NULL);
	data->map.input_map = malloc(sizeof(int *) * (data->map.height + 1));
	while (i < data->map.height)
		data->map.input_map[i++] = malloc(sizeof(int) * data->map.width);
	i = 0;
	line = get_next_line(fd);
	while (i < data->map.height && line)
	{
		parse_map_line(data->map.input_map[i++], data->map.width, line);
		line = get_next_line(fd);
	}
	data->map.input_map[data->map.height] = NULL;
	close(fd);
	return (data);
}

//width = no of integers in a line i.e. columns
//height = no of lines i.e. rows
//determines the dimensions of the map by reading the file line by line
int	get_size(char *file, int *height, int *width)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL; //necessary?
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	*width = count_words(line, ' ');
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

int	*parse_map_line(int *row, int column_count, char *line_content)
{
	int		i;
	char	**number;

	i = 0;
	number = ft_split(line_content, ' ');
	while (i < column_count)
	{
		row[i] = ft_atoi(number[i]);
		i++;
	}
	free_arr(number);
	return (row);
}
