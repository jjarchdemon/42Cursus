/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:07:36 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 11:17:01 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//represent a single coordinate in 3D space
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

/*
	void    *img_ptr;       // Pointer to the image itself
	char    *data_addr;     // Pointer to the start of the image memory
	int     bits_per_pixel; // Will be 32 bits (4 bytes)
	int     size_line;      // Number of bytes in one row
	int     endian;         // How color bytes are stored (0 or 1)
*/
typedef struct s_img
{
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

/*
	1. MLX Data: Manages the window
	void    *mlx_ptr;   //  pointer to the graphics system
	void    *win_ptr;   //  pointer to your new window

	2. Map Data: Stores the parsed map
	int     **z_map;    // 2D array of all 'z' (altitude) values
	int     height;     // Number of rows (map's Y)
	int     width;      // Number of columns (map's X)

	3. Image Data: Manages your image buffer
	t_img   *img;       // A pointer to your image struct
	
	4. Control Data: For transformations
	int     zoom;       // multiplier
	int     x_offset;   // for centering
	int     y_offset;   // for centering
	float   angle;      // for isometric projection (tilt)
*/
typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**z_map;
	int		height;
	int		width;
	t_img	*img;
	int		zoom;
	int		x_offset;
	int		y_offset;
	float	angle;
}	t_fdf;
