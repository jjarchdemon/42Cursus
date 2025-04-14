/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:59 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:45:04 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	blend_color(int color_start, int color_end, double fraction)
{
    int	red;
    int	green;
    int	blue;

    red = (int)(((color_start >> 16) & 0xFF) * (1 - fraction) +
                ((color_end >> 16) & 0xFF) * fraction);
    green = (int)(((color_start >> 8) & 0xFF) * (1 - fraction) +
                  ((color_end >> 8) & 0xFF) * fraction);
    blue = (int)((color_start & 0xFF) * (1 - fraction) +
                 (color_end & 0xFF) * fraction);
    return ((red << 16) | (green << 8) | blue);
}
