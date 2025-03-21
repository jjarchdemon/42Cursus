/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:02 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/23 14:16:49 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_digits(int n)
{
	int	count;

	if (n <= 0)
		count = 1;
	else
		count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*result;

	num = n;
	len = count_digits(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		result[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
	printf("the number is : %s\n", ft_itoa(5578));
	printf("the number is : %s\n", ft_itoa(-13415245));
	printf("the number is : %s\n", ft_itoa(0));
	printf("the number is : %s\n", ft_itoa(000));
	return (0);
}
*/
