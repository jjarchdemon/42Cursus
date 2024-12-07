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

int	ft_putchar(int c)
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

int	ft_putnumbr(long num)
{
	int	count;

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

int     ft_puthex(unsigned long nb, char letter)
{
        int     count;
        char    *base;

        count = 0;
        if (letter == 'x')
                base = "0123456789abcdef";
        else
                base = "0123456789ABCDEF";
        if (nb >= 16) //TODO still to understand
                count += ft_puthex(nb / 16, letter);
        count += ft_putchar(base[nb % 16]);
        return (count);
}

int     ft_putptr(void *ptr) 
{
        int     count;

        count = 0;
        count += ft_putstr("0x");
        if (ptr == 0)
                count += ft_putchar('0');
        else
                count += ft_puthex((unsigned long)ptr, 'x'); //TODO wtf?
        return (count);
}
