/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:20:09 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 12:58:50 by jambatt          ###   ########.fr       */
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

	fdf->height = get_height(filename);
	fdf->width = get_width(filename);
	fdf->z_map = malloc(fdf->height * sizeof(int *));
	fd = open(filename, O_RDONLY);
	row = 0;
	while (get_next_line(fd))
	{
		fdf->z_map[row] = malloc(fdf->width * sizeof(int));
		fill_z_map(fdf->z_map[row], line);
		row++;
	}
	close(fd);
}

static int	get_height(char *file_path)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

static int	get_width(char *file_path)
{
	int		fd;
	char	*line;
	char	**words;
	int		width;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	words = ft_split(line, ' ');
	width = 0;
	while (words[width])
		width++;
	close(fd);
	return (width);
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