/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:44:21 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/06 17:12:43 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count;

	count = (int)write(1, &c, 1);
	return (count);
}

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}
/*
int	ft_putnumbr(int nb, int issigned) //TODO for unsigned int ?
{
	unsigned long	num;
	int	count;

	//num = (long)nb;//TODO error handling
	count = 0;
	if (issigned)
	{
		if (nb < 0)
		{
			count += ft_putchar('-');
			num = (unsigned long)-nb;
		}
		else
			num = (unsigned long)nb;
	}
	else
		num = (unsigned long)nb;
	if (num == 0 && count == 0)
		count += ft_putchar('0');
	if (num >= 10)
		count += ft_putnumbr(num / 10, issigned);
	count += ft_putchar((num % 10) + '0');
	return (count);
}
*/
