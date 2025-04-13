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

# define WIDTH 1920
# define HEIGHT 1080

# define ESCAPE 65307

//Used for scaling the map dimensions to fit within the rendering window.
typedef struct s_map_scale
{
	int	scale_factor;
	int	max_dimension;
	int	x_scale;
	int	y_scale;
}	t_map_scale;
/*
- `scale_factor`: The factor by which the map is scaled.
- `max_dimension`:largest dimension of the map (width, height, or z-range).
- `x_scale` and `y_scale`: Scaling factors for the x and y axes.
*/

//Represents the start and end points of a line to be drawn.
typedef struct s_line_points
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
}	t_line_points;
/*
- `x1`, `y1`: Coordinates of the starting point.
- `x2`, `y2`: Coordinates of the ending point.
*/

// Stores data related to a line
typedef struct s_line_data
{
	int	z1;
	int	z2;
	int	dx;
	int	dy;
	int	iso;
}	t_line_data;
/*
- `z1`, `z2`: Heights (z-values) at the start and end points of the line.
- `dx`, `dy`: Diff in x and y coordinates between the start and end pts.
- `iso`: A flag or value for isometric projection adjustments.
*/

//Represents the map data, including its dimensions and height values.
typedef struct s_map
{
	int	height;
	int	width;
	int	max_z;
	int	min_z;
	int	***input_map;
}	t_map;
/*
- `height`, `width`: Dimensions of the map.
- `max_z`, `min_z`: Maximum and minimum z-values (heights) in the map.
- `input_map`: 3D array storing height & optional color values for each pt.
*/

// The main struct for the program for rendering and managing the map.
typedef struct s_fdf
{
	void			*mlx;
	void			*img;
	void			*wnd;
	int				bpp;
	int				size_line;
	int				endian;
	char			*address_data;
	t_line_data		side;
	t_map			dmap;
	float			scale_factor;
}	t_fdf;
/*
- `mlx`, `img`, `wnd`: Pointers to the MiniLibX context, image, and window.
- `address_data`: Pointer to the image data buffer.
- `side`: A `t_line_data` struct for storing line-related data.
- `dmap`: A `t_map` struct for storing the map data.
- `scale_factor`: The scaling factor applied to the map.
*/

//read_map_data
t_fdf			*read_map_data(t_fdf *data, char *file);
int				get_size(char *file, int *height, int *width);
int				*parse_map_line(int **row, int column_count,
					char *line_content);
int				find_max_z(t_fdf *data);
int				find_min_z(t_fdf *data);
//draw
void			set_pixels(t_fdf *data);
void			draw_map(t_fdf *data);
void			line(int x2, int y2, t_fdf *data, t_line_points p);
void			reproduce_pixels(t_line_points *p, t_fdf *data);
void			locate(t_line_points *p, t_fdf *data);

//algo
void			negative_slope(int x1, int y1, t_fdf *data, int color1, int color2);
void			positive_slope(int x1, int y1, t_fdf *data, int color1, int color2);
void			isometric(int *x, int *y, int z);

//utils
int				clean_close(t_fdf *data);
t_fdf			*create_fdf_data(void);
void			free_arr(char **str);
void			free_map(int ***arr, int height, int width);

int				handle_keypress(int key, t_fdf *data);
void			draw_pixel(t_fdf *data, int x, int y, int color);

//color

unsigned int	get_color(int z1, int z2);
unsigned int	get_default_color(int z, t_fdf *data);

//more utils?
int				ft_atoi_base(const char *str);
size_t			count_words(char const *s, char c);
#endif
