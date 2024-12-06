/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:23:35 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/06 14:56:27 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ag;
	int		count;

	count = 0;
	va_start(ag, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += pick_formatter(ag, *(s + 1));
			s++;
			if (count == -1)
				return (-1);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(ag);
	return (count);
}
/*
#include <stdio.h>
int main()
{
	int ft_count = ft_printf("This is an int: %i\n", 52);
	printf("printed: %i chars\n", ft_count);
	int count = printf("This is an int: %i\n", 52);
	printf("printed: %i chars\n", count);
	if (ft_count == count)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");
	int ft_countc = ft_printf(" %c %c %c ", '0', 0, '1');
	printf("my printed: %i chars\n", ft_count);
	int countc = printf(" %c %c %c ", '0', 0, '1');
	printf("og printed: %i chars\n", count);
	if (ft_countc == countc)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");
	int ft_countc1 = ft_printf(" %c %c %c ", '1', '2', '3');
	printf("my printed: %i chars\n", ft_count);
	int countc1 = printf(" %c %c %c ", '1', '2', '3');
	printf("og printed: %i chars\n", count);
	if (ft_countc1 == countc1)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");
	int ft_count1 = ft_printf("This is: %d\n",-152);
	printf("printed: %i chars\n", ft_count1);
	int count1 = printf("This is: %d\n", -152);
	printf("printed: %i chars\n", count1);
	if (ft_count1 == count1)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");
	int ft_count2 = ft_printf("This is: %s\n", "String");
	printf("printed: %i chars\n", ft_count2);
	int count2 = printf("This is: %s\n", "String");
	printf("printed: %i chars\n", count2);
	if (ft_count2 == count2)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");
	int count3 = printf("This is: %u\n", -52);
	printf("printed: %i chars\n", count3);
	int ft_count3 = ft_printf("This is: %u\n", -52); 
	printf("printed: %i chars\n", ft_count3);
	if (ft_count3 == count3)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");
	int ft_count4 = ft_printf("This is: %x\n", 123456);
	printf("printed: %i chars\n", ft_count4);
	int count4 = printf("This is: %x\n", 123456	);
	printf("printed: %i chars\n", count4);
	if (ft_count4 == count4)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");
	char *nullptr = NULL;
	int count5 = printf(" NULL %s NULL ", nullptr);//NULL);
	printf("printed: %i chars\n", count);
	int ft_count5 = ft_printf(" NULL %s NULL ", nullptr);//NULL);
	printf("printed: %i chars\n", ft_count);
	if (ft_count5 == count5)
		printf("\033[32mPassed\033[0m\n");
	else
		printf("\033[1;31mFailed\033[0m\n");
	printf("********************************************\n");

	return(1);
}
*/
