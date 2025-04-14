/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_line_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:46:26 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:46:28 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap(int *a, int *b);

void	swap_line_values(t_line *line)
{
	swap(&(line->x0), &(line->x1));
	swap(&(line->y0), &(line->y1));
	swap(&(line->color_start), &(line->color_end));
	return ;
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}
