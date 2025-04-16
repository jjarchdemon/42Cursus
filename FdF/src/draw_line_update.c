/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:29 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/16 12:37:07 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
 * File Description:
 * This file contains helper functions for updating the coordinates and
 * decision parameters used in the Bresenham line-drawing algorithm. These
 * functions handle horizontal and vertical updates during the line-drawing
 * process.
 */

/*
 * - update_horizontal_values: Updates the horizontal coordinate and decision
 *   parameter when drawing a line with a shallow slope.
 */
 void	update_horizontal_values(t_line *l, int *p, int *coordinate, int dir)
{
	if (*p >= 0)
	{
		*coordinate = *coordinate + dir;
		*p = *p - (2 * l->dx);
	}
	*p = *p + (2 * l->dy);
}

/*
 * - update_vertical_values: Updates the vertical coordinate and decision
 *   parameter when drawing a line with a steep slope.
 */
void	update_vertical_values(t_line *l, int *p, int *coordinate, int dir)
{
	if (*p >= 0)
	{
		*coordinate = *coordinate + dir;
		*p = *p - (2 * l->dy);
	}
	*p = *p + (2 * l->dx);
}
