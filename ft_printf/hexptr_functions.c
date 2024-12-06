/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexptr_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:17:49 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/06 16:30:32 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, char letter)
{
	int	count;

	count = 0;//TODO error handling
	if (nb >= 16)
		count += ft_puthex(nb / 16, letter);
	if (nb % 16 < 10) //TODO understand this ifelse  properly
		count += ft_putchar((nb % 16) + '0');
	else
		count += ft_putchar((nb % 16) - 10 + letter);
	return (count);
}

int	ft_putptr(void * ptr) //TODO ptr function
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	if (ptr == 0)
		count += ft_putchar('0');
	else
		count += ft_puthex((unsigned long)ptr, 'x');
	return (count);
}
