/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:59 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:45:04 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_blue(int color);
static int	get_green(int color);
static int	get_red(int color);
static int	interpolate_channel(int start, int end, double fraction);

int	interpolate_color(int color_start, int color_end, double fraction)
{
	int	blue;
	int	green;
	int	red;
	int	result;

	red = interpolate_channel(get_red(color_start), get_red(color_end),
			fraction);
	green = interpolate_channel(get_green(color_start), get_green(color_end),
			fraction);
	blue = interpolate_channel(get_blue(color_start), get_blue(color_end),
			fraction);
	result = (red << 16) | (green << 8) | blue;
	return (result);
}

static int	interpolate_channel(int start, int end, double fraction)
{
	double	result;

	result = start + fraction * (end - start);
	return ((int)result);
}

static int	get_blue(int color)
{
	int	blue;

	blue = color & 0xFF;
	return (blue);
}

static int	get_green(int color)
{
	int	green;

	green = (color >> 8) & 0xFF;
	return (green);
}

static int	get_red(int color)
{
	int	red;

	red = (color >> 16) & 0xFF;
	return (red);
}
