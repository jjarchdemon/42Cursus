/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:01:47 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 15:03:23 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_with_error(t_fdf *fdf, char *error_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_msg, 2);
	deinit_fdf(fdf);
	exit(1);
}

void	exit_cleanly(t_fdf *fdf)
{
	deinit_fdf(fdf);
	exit(0);
}