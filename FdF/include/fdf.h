/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:31:45 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/10 11:55:26 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./my_libft/libft.h"		//stddef
# include "./my_libft/get_next_line.h"	//stdlib stdint unistd fcntl
# include "./my_libft/ft_printf.h"	//unistd stdarg
# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

//# include <mlx.h>
//# include <X11/keysym.h>
//# include <X11/X.h>

# define WIDTH 1000
# define HEIGHT 800
# define DEFAULT_COLOR 0xFFFFFF
# define BLACK 0x000000
# define ANGLE 0.610865	// 35
//# define ANGLE 0.523599	// 30
typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				x_projected;
	int				y_projected;
	int				z_current;
	unsigned int	color;
}	t_point;

typedef struct s_data
{
	void	*server;
	void	*window;
	void	*image;
	char	*image_addr;
	t_point	***map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_dim_x;
	int		map_dim_y;
	int		scale;
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;
	int		offset_x;
	int		offset_y;
}	t_data;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	dx;
	int	dy;
	int	color_start;
	int	color_end;
}	t_line;

void	clear_image(t_data *data);
int		close_window(void *param);
void	draw_line(t_data *data, t_line l);
void	draw_map(t_data *data);
void	free_all(char *l, char **ss, t_point **p);
void	free_all_points_content(t_point ***map, int index);
void	free_map(t_point ***map);
void	free_points_arr(t_point **points, int index);
void	free_split_stuff(char **split_stuff);
int		get_char_array_length(char **arr);
int		get_point_array_length(t_point **arr);
int		handle_key_events(int keycode, void *param);
int		hex_atoi(char *str);
t_data	*initialize_data(void);
void	initialize_graphics(t_data *data);
int		interpolate_color(int color_start, int color_end, double fraction);
int		min(int a, int b);
void	empty_map_error(t_data *data);
void	file_error(t_data *data);
void	allocation_error(t_data *data);
void	argument_error(void);
t_point	**process_line(char *line, int line_index, t_data *data);
void	load_map_data(char *filename, t_data *data);
t_point	*process_word(char *word, int row_index, int col_index);
void	swap_line_values(t_line *line);
void	transform_map(t_data *data);
void	update_horizontal_values(t_line *l, int *p, int *coordinate, int dir);
void	update_vertical_values(t_line *l, int *p, int *coordinate, int dir);

#endif
