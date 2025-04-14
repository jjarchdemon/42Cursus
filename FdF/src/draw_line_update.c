/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:29 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:42:33 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_horizontal_values(t_line *l, int *p, int *coordinate, int dir)
{
	if (*p >= 0)
	{
		*coordinate = *coordinate + dir;
		*p = *p - (2 * l->dx);
	}
	*p = *p + (2 * l->dy);
}

void	update_vertical_values(t_line *l, int *p, int *coordinate, int dir)
{
	if (*p >= 0)
	{
		*coordinate = *coordinate + dir;
		*p = *p - (2 * l->dy);
	}
	*p = *p + (2 * l->dx);
}
