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

//TODO 
//	%p
//	%%

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

int	ft_putint(int nb, int issigned)
{
	long	num;
	int	count;

	num = (long)nb;//TODO error handling
	count = 0;
	if (issigned)
	{
		if (num < 0)
		{
			count += ft_putchar('-');
			num = -num;
		}
	}
	if (num == 0 && count == 0)
		count += ft_putchar('0');
	if (num >= 10)
		count += ft_putint(num / 10, issigned);
	count += ft_putchar((num % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned int nb, char letter)//TODO verify the type
{
	int	count;
	unsigned long num;

	num = (unsigned long)nb;//TODO necessary
	count = 0; 		//TODO error handling
	if (num >= 16)
		count += ft_puthex(num / 16, letter);
	if (num % 16 < 10)	//TODO understand this ifelse  properly
		count += ft_putchar((num % 16) + '0');
	else
		count += ft_putchar((num % 16) - 10 + letter);
	return (count);
}

#include <stdio.h>

int main()
{
	char	*s = "123456789";
	char c = 'c';
	int negnbr = -123456789;
	int nbr = 123456789;
	printf(" contains :%i chars\n", ft_putchar(c));
	printf(" contains :%i chars\n", ft_putstr(s));
	printf(" contains :%i chars\n", ft_putint(nbr, 1));
	printf(" contains :%i chars\n", ft_putint(negnbr, 1));
	printf(" contains :%i chars\n", ft_puthex(nbr, 'a'));
	printf(" contains :%i chars\n", ft_puthex(nbr, 'A'));
	printf("Void pointer is %p\n", NULL);
}












