/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:39:44 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/04 13:58:16 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// what i typed to get the compiler not throw errors
// gcc -o test test.c -lmlx -lX11 -lXext -lm

#include "mlx_linux/mlx.h"

#define WIDTH 500
#define HEIGHT 500

int main ()
{
	void *mlx_connection;
	//void *mlx_window;

	mlx_connection = mlx_init(); //starts a connection
	//mlx_window = mlx_new_window(mlx_connection, 600, 600, "New Window");
	
	void *img;
	img = mlx_new_image(mlx_connection, 300, 300);
	//putting a white pixel on the screen
	//mlx_pixel_put(mlx_connection, mlx_window, 300, 300, 0xffffff); 
/*	
	//putting a line on the screen	
	int i = 0;
	while (i<201)
	{
		mlx_pixel_put(mlx_connection, mlx_window, 200 + i, 300, 0xffffff);
		i++;
	}

	//putting a diagonal line on the screen	
	int y = 0;
	while (y < 201)
	{
		mlx_pixel_put(mlx_connection, mlx_window, 200 + y, 200 + y, 0x00ff00);
		y++;
	}
*/

	//mlx_loop(mlx_connection);
}

