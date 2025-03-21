/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:51:08 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/27 16:18:59 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	val = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		p[i] = val;
		i++;
	}
	return (ptr);
}
