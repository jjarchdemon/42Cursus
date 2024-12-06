/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:44:21 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/05 17:29:47 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	int	count;

	count = (int)write(1, &c, 1);//TODO error handling?
	return (count);
}

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	while(*str)//TODO error handling?
	{
		count += ft_putchar(*str);
		str++;
	}
	return(count);
}

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

int	ft_puthex(unsigned int nb, char letter)
{
	int	count;
	unsigned long num;

	num = (unsigned long)nb;//TODO necessary?
	count = 0;		//TODO error handling
	if (num >= 16)
		count += ft_puthex(num / 16, letter);
	if (num % 16 < 10)	//TODO understand this ifelse  properly
		count += ft_putchar((num % 16) + '0');
	else
		count += ft_putchar((num % 16) - 10 + letter);
	return (count);
}

int	ft_putptr(unsigned long long ptr) //TODO ptr function
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	if (ptr == 0)
		count += ft_putchar('0');
	else
		ft_puthex((unsigned int)ptr, 'x');
	return (count);
}
