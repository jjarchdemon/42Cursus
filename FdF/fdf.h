/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:31:45 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/07 15:44:46 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./my_libft/ft_printf.h"
# include "./mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ESCAPE 65307

typedef struct s_point
{
	int     x;
	int     y;
	int     z;
	int     color;
	int     reverse;
}	t_point;


typedef struct map
{
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
}	t_map;

typedef struct camera
{
	int	zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_height;
	int	x_offset;
	int	y_offset;
	int	iso;
}	t_camera;

typedef struct data_dump
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_map	*map;
}	t_dd;
#endif
