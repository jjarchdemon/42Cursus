/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:34:13 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/25 17:32:34 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stddef.h>  //for count_words

//calculates a color based on two input values, z1 and z2.
//blend between red and green, based on the average of z1 and z2.
//returns an unsigned integer in the format 0xRRGGBB.
unsigned int	get_color(int z1, int z2)
{
	float	blend_ratio;
	int		red;
	int		green;

	blend_ratio = (((z1 + z2) / 2.0) + 50.0) / 150.0;
	red = (int)(blend_ratio * 255);
	green = (int)((1 - blend_ratio) * 255);
	return ((red << 16) | (green << 8) | 100);
}

//TODO delete this shit, figure it out
size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

// Blue Green Yellow Orange Red
unsigned int	get_default_color(int z, fdf *data)
{
	float	percentage;

	percentage = (float)(z - data->map.min_z)
		/ (data->map.max_z - data->map.min_z);
	if (percentage < 0.2)
		return (0x0000FF);
	else if (percentage < 0.4)
		return (0x00FF00);
	else if (percentage < 0.6)
		return (0xFFFF00);
	else if (percentage < 0.8)
		return (0xFFA500);
	else
		return (0xFF0000);
}
