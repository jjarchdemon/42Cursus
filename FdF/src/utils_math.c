/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:30 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:45:32 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

double	deg_to_rad(int d)
{
	double	r;
	int		sign;

	sign = 1;
	if (d < 0)
		sign = -1;
	d *= sign;
	while (d >= 360)
		d -= 360;
	r = (double)((((double) d) / 360) * (2 * M_PI));
	r *= sign;
	return (r);
}
