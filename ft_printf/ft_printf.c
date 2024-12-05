/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:23:35 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/05 15:23:48 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int	return_value;

	return_value = 0;
	if (!s)
		return (-1); //TODO verify this
	while (*s)
	{
		if (*s == '%')
		{
			//TODO add functions to deal with respective values
		}
		//TODO function to write char
	}
	return (1);//TODO return no of char
}
