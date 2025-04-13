#include "../include/fdf.h"

int	find_max_z(t_fdf *data)
{
    int	max_z;
    int	i;
    int	j;

    if (!data || !data->dmap.input_map || data->dmap.height == 0 || data->dmap.width == 0)
        return (0); // Return 0 or an appropriate default value if the map is invalid.

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

    if (!data || !data->dmap.input_map || data->dmap.height == 0 || data->dmap.width == 0)
        return (0); // Return 0 or an appropriate default value if the map is invalid.

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

//width = no of integers in a line i.e. columns
//height = no of lines i.e. rows
//determines the dimensions of the data_map by reading the file line by line
int	get_size(char *file, int *height, int *width)
{
    int		i;
    int		fd;
    char	*line;

    if (!file || !height || !width)
        return (-1); // Invalid input.

    i = 0;
    line = NULL;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1); // File could not be opened.

    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (-1); // File is empty.
    }

    *width = count_words(line, ' ');
    if (*width == 0)
    {
        free(line);
        close(fd);
        return (-1); // First line is empty or invalid.
    }

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