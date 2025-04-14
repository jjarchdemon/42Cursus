/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:59 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:46:01 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_lines(int fd);
static void	process_file(int fd, t_data *data);
static void	set_scale(t_data *data);

void	process_map(char *filename, t_data *data)
{
	t_point	***map;
	int		fd;
	int		line_count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_file_error(data);
	line_count = count_lines(fd);
	close(fd);
	if (line_count == 0)
		print_empty_map(data);
	map = malloc(sizeof (t_point **) * (line_count + 1));
	if (!map)
		print_memory_error(data);
	data->map = map;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_file_error(data);
	process_file(fd, data);
	close(fd);
	data->map_dim_y = line_count;
	set_scale(data);
	return ;
}

static void	process_file(int fd, t_data *data)
{
	int		line_index;
	char	*line;
	t_point	***map;

	line_index = 0;
	line = get_next_line(fd);
	map = data->map;
	while (line)
	{
		map[line_index] = process_line(line, line_index, data);
		if (!(map[line_index]))
		{
			free_all_points_content(map, --line_index);
			free(map);
			data->map = NULL;
			free(line);
			print_memory_error(data);
		}
		free(line);
		line = get_next_line(fd);
		++line_index;
	}
	map[line_index] = NULL;
	return ;
}

static int	count_lines(int fd)
{
	char	*line;
	int		line_count;

	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		++line_count;
		free(line);
		line = get_next_line(fd);
	}
	return (line_count);
}

static void	set_scale(t_data *data)
{
	int	scale;
	int	scale_x;
	int	scale_y;

	scale = 1;
	scale_x = SIZE_X / 2;
	if ((data->map_dim_x - 1) > 0)
		scale_x /= (data->map_dim_x);
	scale_y = SIZE_Y / 2;
	if ((data->map_dim_y - 1) > 0)
		scale_y /= (data->map_dim_y);
	scale = min(scale_x, scale_y);
	if (scale > 0)
		data->scale = scale;
	return ;
}
