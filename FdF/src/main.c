/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:19:09 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 15:07:42 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (1);
	init_fdf(&fdf);
	parse_map(av[1], &fdf);//TODO: error handling for arguments

	my_mlx_pixel_put(fdf.img, 50, 50, WHITE);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img->img_ptr, 0, 0);

	mlx_key_hook(fdf.win_ptr, key_hook, &fdf);//esc
	mlx_hook(fdf.win_ptr, ON_DESTROY, 0, close_program, &fdf);//x button
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
