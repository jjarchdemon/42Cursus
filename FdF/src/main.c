/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:19:09 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 12:39:08 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char *av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (1);
	init_fdf(&fdf);
	parse_map(av[1], &fdf);//TODO: error handling for arguments
	mlx_key_hook(fdf.win_ptr, key_hook, &fdf);//esc
	mlx_hook(fdf.win_ptr, ON_DESTROY, 0, close_program, &fdf);//x button
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
