/* ************************************************************************** */
#include "fdf.h"

int	get_height(char *map)
{
	int	fd;
	int	height;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror("Error opening file");
	height = 0;
	line = get_next_line(fd)
	while (line != NULL && *line != '\0')
	{
		height++;
		free(line);
	}
	if (line)
		free(line);
	if (close(fd) < 0)
		perror("Error closing file");
	return(height);
}

int	get_width(char *map)
{
	int	fd;
	int	width;
	char	*line;
	int	i;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror("Error opening file ");
	width = 0;
	line = get_next_line(fd);
	if (line == NULL || *line =='\0')
		perror("No map or invalid map");
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i+1] == ' '|| line[i+1] == '\0' ))
			width++;
		i++;
	}
	free(line);
	while ((line = get_next_line(fd)) != NULL)
		free(line);
	if (close(fd) < 0)
		perror("Error closing file");
	return(width);
}

void	get_zheight_&_color(int **row_data, char *line, int width)
{
	char	**numbers;	//array of strings representing numbers in line
	int	i;
	int	j;
	char	*number_str;
	char	*comma_pos;
	char	*color_str;

	numbers = ft_split(line);
	i = 0;
	while (numbers[i] != NULL && i < width)
	{
		row_data[i] = malloc(sizeof(int) * 2);
		if (row_data[i] == NULL)
		{
			perror("Malloc error");
			return;
		}
		number_str = numbers[i];
		comma_pos = ft_strchr(number_str, ',');
		if (comma_pos != NULL)
		{
			*comma_pos = '\0';
			row_data[i][0] = ft_atoi(number_str);
			color_str = comma_pos + 1;
			row_data[i][1] = ft_atoi_base(color_str,"0123456789ABCDEF"); //TODO atoi_base
		} else 
		{
			row_data[i][0] = ft_atoi(number_str);
			row_data[i][1] = -1;
		}
		free(numbers[i]);
		i++;
	}
	if (i != width || numbers[i] != NULL)
		perror("map has irregular width");
	free(numbers);
}

void	get_zminmax(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
                                map->z_min = map->array[i][j][0];
                        if (map->array[i][j][0] > map->z_max)
                                map->z_max = map->array[i][j][0];
                        j++;
		}
		i++;
	}
}

//TODO function for checking valid map














