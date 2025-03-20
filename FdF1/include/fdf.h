/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:31:45 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 13:56:32 by jambatt          ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 400

# define ESCAPE 65307

//# define MAX_KEYS 65536	//TODO what is this

typedef	struct
{
	int	scale_factor;	//scale
	int	max_dimension; //max_d
	int	x_scale;
	int	y_scale;
}	map_scale;	//custom;

typedef	struct
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
}	line_points;	//t_point
/*
typedef	struct
{
	int	offset_x;
	int	offset_y;
	int	zoom;
	int	shift_up;
	int	shift_down;
	int	shift_right;
	int	shift_left;
	int	key_states[MAX_KEYS];	//TODO what is this
}	view_control;	//control
*/
typedef	struct
{
	int	z1;
	int	z2;
	int	dx;
	int	dy;
	int	iso;
}	line_data;	//pixels;

typedef	struct
{
	int	height;
	int	width;
	int	**input_map;//render_map
}	map;

typedef	struct
{
	void			*mlx;
	void			*img;
	void			*wnd;
	int				bpp;
	int				size_line;
	int				endian;
	char			*address_data;
	//view_control	window;
	line_data		side;
	map				map;
}	fdf;

//read_map_data
fdf	*read_map_data(fdf *data, char *file);
int	get_size(char *file, int *height, int *width);
int	*parse_map_line(int *map_line, int width, char *line);
//draw
void	set_pixels(fdf *data);
void	draw_map(fdf *data);
void	line(int x2, int y2, fdf *data, line_points p);
void	reproduce_pixels(line_points *p, fdf *data);
void	locate(line_points *p, fdf *data);

//algo
void	negative_slope(int x1, int y1, fdf *data);
void	positive_slope(int x1, int y1, fdf *data);
void	isometric(int *x, int *y, int z);

//utils
int	clean_close(fdf *data);
fdf	*create_fdf_data(void);
void	free_arr(char **str);
void	free_map(int **arr);

int	handle_keypress(int key, fdf *data);
void	draw_pixel(fdf *data, int x, int y, int color);

//color
unsigned int	get_color(int z1, int z2);

size_t	count_words(char const *s, char c);//TODO delete this

#endif
