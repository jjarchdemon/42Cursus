/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:19:09 by jambatt           #+#    #+#             */
/*   Updated: 2025/11/21 16:23:03 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	#ifdef __APPLE__
		printf("this is a mac\n");
	#endif

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	(void)mlx_win;
	mlx_loop(mlx);
}
