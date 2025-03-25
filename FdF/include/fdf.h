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

# define WIDTH 1920
# define HEIGHT 1080

# define ESCAPE 65307

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
	int	max_z;
	int	min_z;
	int	***input_map;//3D array to store height & optional color
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
	float scale_factor; // Add this field to store the scaling factor
}	fdf;

//read_map_data
fdf	*read_map_data(fdf *data, char *file);
int	get_size(char *file, int *height, int *width);
int	*parse_map_line(int **row, int column_count, char *line_content);
int	find_max_z(fdf *data);
int	find_min_z(fdf *data);
//draw
void	set_pixels(fdf *data);
void	draw_map(fdf *data);
void	line(int x2, int y2, fdf *data, line_points p);
void	reproduce_pixels(line_points *p, fdf *data);
void	locate(line_points *p, fdf *data);

//algo
void	negative_slope(int x1, int y1, fdf *data, int color1, int color2);
void	positive_slope(int x1, int y1, fdf *data, int color1, int color2);
void	isometric(int *x, int *y, int z);

//utils
int	clean_close(fdf *data);
fdf	*create_fdf_data(void);
void	free_arr(char **str);
void	free_map(int ***arr, int height, int width);

int	handle_keypress(int key, fdf *data);
void	draw_pixel(fdf *data, int x, int y, int color);

//color
unsigned int	get_color(int z1, int z2);

size_t	count_words(char const *s, char c);//TODO delete this

unsigned int	get_default_color(int z, fdf *data);
int ft_atoi_base(const char *str);

#endif
