/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:20:09 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 13:55:05 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		get_height(char *file_path);
static int		get_width(char *file_path);
static void		fill_z_map(int *z_line, char *line);

void	parse_map(char *filename, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		row;

	line = NULL;
	fdf->height = get_height(filename);
	fdf->width = get_width(filename);
	fdf->z_map = malloc(fdf->height * sizeof(int *));
	fd = open(filename, O_RDONLY);
	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		fdf->z_map[row] = malloc(fdf->width * sizeof(int));
		if (!fdf->z_map[row])
			return ;//TODO: need a clean up function here
		fill_z_map(fdf->z_map[row], line);
		row++;
	}
	close(fd);
	print_z_map(fdf);//DEBUG
}

static int	get_height(char *file_path)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

//TODO: understand this in depth
static int	get_width(char *file_path)
{
	int		fd;
	char	*line;
	int		width;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	width = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
		{
			width++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
		}
		else
			i++;
	}
	free(line);
	while ((line = get_next_line(fd)))
		free(line);
	return (close(fd), width);
}

//TODO: understand this in depth
static void	fill_z_map(int *z_line, char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	i = 0;
	while (words[i])
	{
		z_line[i] = ft_atoi(words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	free(line);
}
//TODO: remove comments
/*
FUNCTION parse_map(file_path, fdf_struct):
    1. Open file
    2. While (GNL returns a line):
        Increment height
        If it's the first line, count words to get width
        Free the line
    3. Close file

    4. Allocate memory for fdf_struct->z_map (height * sizeof(int *))
    
    5. Re-open file
    6. For each row from 0 to height:
        Get line using GNL
        Allocate memory for z_map[row] (width * sizeof(int))
        Split the line into an array of strings (using ft_split)
        For each string in the array:
            Convert string to integer (using ft_atoi)
            Store integer in z_map[row][column]
            Free the individual string
        Free the array of strings and the line
    7. Close file
*/