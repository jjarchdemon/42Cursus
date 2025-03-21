/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:24:24 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/07 15:38:38 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cc fdf.c -L./my_libft -lft -lmlx -lX11 -lXext -lm -o fdf 

#include "fdf.h"

//function for closing window
int	close_window(int key,void *params)
{
	t_dd	*dd;
	dd = (t_dd *)params;
	if (key == ESCAPE)
	{
		mlx_clear_window(dd->mlx, dd->win);
		mlx_destroy_image(dd->mlx, dd->img);
		mlx_destroy_window(dd->mlx, dd->win);
		exit(0);
	}
	return (0);
}

static t_dd	*init_dd(char *str)
{
	t_dd	*dd;

	dd = malloc(sizeof(t_dd));
	if (!dd)
	{
		free(dd);
		perror("Could not malloc");
	}
	dd->mlx = mlx_init();
	dd->win = mlx_new_window(dd->mlx, WIDTH, HEIGHT, str);
	dd->img = mlx_new_image(dd->mlx, WIDTH, HEIGHT);
	dd->data_addr = mlx_get_data_addr(dd->img, &dd->bpp, &dd->size_line,
	 &dd->endian); 

	mlx_key_hook(dd->win, close_window, dd);
	mlx_loop(dd->mlx);

	return (dd);
}


int	main(int ac, char **av)
{
	t_dd	*dd;
	if (ac == 2)
	{
		//check if it ends in .fdf

		// if all ok, then
		//0. inititalise the structure
		dd = init_dd(av[1]); 

		//1. parse map -> convert to lines
		//2. load it into image 
		//3. push image to window
		//4. display window
		
	}
	else
		ft_printf("Please input correct arguments\n");
}
