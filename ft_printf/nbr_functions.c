/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:10:12 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/06 15:04:02 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumbr(int nb)
{
	long	num;
	int		count;

	num = (long)nb;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num == 0 && count == 0)
		return (count += ft_putchar('0'));
	if (num >= 10)
		count += ft_putnumbr(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}

int	ft_putunumbr(unsigned int nb)
{
	unsigned long	num;
	int				count;

	num = (unsigned long)nb;//TODO error handling
	count = 0;
	if (num == 0 && count == 0)
		return (count += ft_putchar('0'));
	if (num >= 10) 
		count += ft_putunumbr(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}
