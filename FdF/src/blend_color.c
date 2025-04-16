/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:59 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/16 12:32:06 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * blend_color - Blends two colors based on a given fraction.
 * @color_start: The starting color in hexadecimal format (e.g., 0xRRGGBB).
 * @color_end: The ending color in hexadecimal format (e.g., 0xRRGGBB).
 * @fraction: A value between 0.0 and 1.0 representing the blend ratio.
 *            - 0.0 results in the starting color.
 *            - 1.0 results in the ending color.
 *
 * This function calculates the interpolated color by blending the red, green,
 * and blue components of the two colors based on the fraction.
 *
 * Return: The blended color in hexadecimal format (0xRRGGBB).
 */
int	blend_color(int color_start, int color_end, double fraction)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(((color_start >> 16) & 0xFF) * (1 - fraction)
			+ ((color_end >> 16) & 0xFF) * fraction);
	green = (int)(((color_start >> 8) & 0xFF) * (1 - fraction)
			+ ((color_end >> 8) & 0xFF) * fraction);
	blue = (int)((color_start & 0xFF) * (1 - fraction)
			+ (color_end & 0xFF) * fraction);
	return ((red << 16) | (green << 8) | blue);
}
