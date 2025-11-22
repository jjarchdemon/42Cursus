/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:44:44 by jambatt           #+#    #+#             */
/*   Updated: 2025/11/22 12:50:32 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    exit_cleanly(t_fdf *fdf)
{
	deinit_fdf(fdf);
	exit(0);
}

int	close_program(t_fdf *fdf)
{
	exit_cleanly(fdf);
	return (0);
}

int key_hook(int keycode, t_fdf *fdf)
{
	printf("Keycode: %d\n", keycode); //for debug
	if (keycode == K_ESC)
		exit_cleanly(fdf);
	return (0);
}