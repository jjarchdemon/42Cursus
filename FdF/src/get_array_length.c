/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:43:32 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/15 12:11:45 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_char_array_length(char **arr)
{
	int	len;

	len = 0;
	if (!arr || *arr == NULL)
		return (0);
	while (*arr)
	{
		++len;
		++arr;
	}
	return (len);
}

int	get_array_length(t_point **arr)
{
	int	len;

	if (!arr || !*arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}
