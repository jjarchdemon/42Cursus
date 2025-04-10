#include "../include/fdf.h"

int	find_max_z(t_fdf *data)
{
	int	max_z;
	int	i;
	int	j;

	max_z = data->data_map.input_map[0][0][0]; 
	i = 0;
	while (i < data->data_map.height)
	{
		j = 0;
		while (j < data->data_map.width)
		{
			if (data->data_map.input_map[i][j][0] > max_z)
				max_z = data->data_map.input_map[i][j][0];
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

	min_z = data->data_map.input_map[0][0][0]; 
	i = 0;
	while (i < data->data_map.height)
	{
		j = 0;
		while (j < data->data_map.width)
		{
			if (data->data_map.input_map[i][j][0] < min_z)
				min_z = data->data_map.input_map[i][j][0];
			j++;
		}
		i++;
	}
	return (min_z);
}

//width = no of integers in a line i.e. columns
//height = no of lines i.e. rows
//determines the dimensions of the data_map by reading the file line by line
int	get_size(char *file, int *height, int *width)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
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