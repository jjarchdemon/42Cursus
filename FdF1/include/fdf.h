/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:31:45 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 11:34:24 by jambatt          ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080

# define ESCAPE 65307

# define MAX_KEYS 65536	//TODO what is this

typedef	struct
{
	int	scale;
	int	max_d;
	int	x_scale;
	int	y_scale;
}	custom;

typedef	struct
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
}	t_point;

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
}	control;

typedef	struct
{
	int	z1;
	int	z2;
	int	dx;
	int	dy;
	int	iso;
}	pixels;

typedef	struct
{
	int	height;
	int	width;
	int	**render_map;
}	map;

typedef	struct
{
	control	window;
	pixels	side;
	map		map;
	int		b_per_pixel;
	int		color;
	int		bvg_color;
	int		size_line;
	int		endian;
	char	*address_data;
	void	*mlx;
	void	*wnd;
	void	*img;
}	fdf;

//readfile
fdf	*readfile(fdf *data, char **file);
int	get_size(int *height, char *file, int *width);
int	*fill_map(int *map_line, int width, char *line);

//draw
void set_pixels(fdf *data);
void draw_map(fdf *data);
void line(int x2, int y2, fdf *data, t_point p);
void reproduce_pixels(t_point *p, fdf *data);
void locate(t_point *p, fdf *data);

//algo
void negative_slope(int x1, int y1, fdf *data);
void positive_slope(int x1, int y1, fdf *data);
void isometric(int *x, int *y, int z);

//utils
void ft_close(fdf *data);
int close_window(fdf *data);
fdf *create_fdf_data(void);
void free_arr(char **str);
void free_map(int **arr);

int	handle_keypress(int key, fdf *data);
void	draw_pixel(fdf *data, int x, int y, int color);

//color
unsigned int get_color(int z1, int z2);

size_t	count_words(char const *s, char c);//TODO delete this
#endif
