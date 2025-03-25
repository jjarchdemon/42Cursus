/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:10 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/25 18:37:51 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*read_map_data(fdf *data, char *file)
{
	int		fd;
	int		i;
	char	*line;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(data), NULL);
	if (get_size(file, &data->map.height, &data->map.width) == 1) //enough?
		return (free(data), NULL);
	//allocate memory for 3D input_map	
	data->map.input_map = malloc(sizeof(int **) * (data->map.height + 1));
	if (!data->map.input_map)
		return (free(data), NULL);
	while (i < data->map.height)
	{
		data->map.input_map[i] = malloc(sizeof(int *) * data->map.width);
		if (!data->map.input_map[i])
		{
			free_map(data->map.input_map, i, data->map.width);
			free(data);
			return (NULL);
		}
		for (int j = 0; j < data->map.width; j++)
		{
			data->map.input_map[i][j] = malloc(sizeof(int) * 2); // [z, color]
			if (!data->map.input_map[i][j])
			{
				free_map(data->map.input_map, i, data->map.width);
				free(data);
				return (NULL);
			}
		}
		i++;
	}
	//read the file line by line and parse the content
	i = 0;
	line = get_next_line(fd);
	while (i < data->map.height && line)
	{
		parse_map_line(data->map.input_map[i], data->map.width, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map.input_map[data->map.height] = NULL;
	data->map.max_z = find_max_z(data);
	data->map.min_z = find_min_z(data);
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

int	*parse_map_line(int **row, int column_count, char *line_content)
{
	int		i;
	char	**number;
	char	**z_and_color;

	i = 0;
	number = ft_split(line_content, ' ');
	while (i < column_count)
	{
		z_and_color = ft_split(number[i], ',');
		row[i][0] = ft_atoi(z_and_color[0]);
		if (z_and_color[1])
			row[i][1] = ft_atoi_base(z_and_color[1]);
		else
			row[i][1] = -1; //default color, how?? what??
		free_arr(z_and_color);
		i++;
	}
	free_arr(number);
	return (*row);
}

int	find_max_z(fdf *data)
{
	int	max_z;
	int	i;
	int	j;

	max_z = data->map.input_map[0][0][0]; // Initialize with the first value
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.input_map[i][j][0] > max_z)
				max_z = data->map.input_map[i][j][0];
			j++;
		}
		i++;
	}
	return (max_z);
}

int	find_min_z(fdf *data)
{
	int	min_z;
	int	i;
	int	j;

	min_z = data->map.input_map[0][0][0]; // Initialize with the first value
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.input_map[i][j][0] < min_z)
				min_z = data->map.input_map[i][j][0];
			j++;
		}
		i++;
	}
	return (min_z);
}
