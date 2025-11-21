/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:56:17 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/27 15:55:47 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *) dest;
	s = (const char *) src;
	if (!dest && !src)
		return (dest);
	if (d < s)
		ft_memcpy(d, s, n);
	else
	{
		d += n;
		s += n;
		while (n > 0)
		{
			d--;
			s--;
			*d = *s;
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h> // for native memmove
#include <assert.h>
#include <stdlib.h>

void test1() 
{
    char src[] = "Hello";
    char dest1[6], dest2[6];  // 5 characters + null terminator

    ft_memmove(dest1, src, 6);  // Copy including the null terminator
    memmove(dest2, src, 6);

    assert(strcmp(dest1, dest2) == 0);
    printf("Test 1: (Basic memmove) Passed\n");
}

void test2() {
    char src[] = "Hello";
    char dest1[6] = {0}, dest2[6] = {0};

    ft_memmove(dest1, src, 0);  // Copy zero bytes
    memmove(dest2, src, 0);

    // Both destination arrays should remain unchanged
    assert(strcmp(dest1, dest2) == 0);
    printf("Test 2: (Zero bytes) Passed\n");
}

void test3() {
    char str[] = "Hello World";
    // Copying a part of the string to a new location in the string
    ft_memmove(str + 6, str, 5);  // Copy "Hello" to "World"
    assert(strcmp(str, "Hello Hello") == 0);  // Check if it worked correctly

    printf("Test 3: (Overlapping memory) Passed\n");
}

void test4() {
    char str[] = "Hello World";
    // Memory overlaps in the opposite direction
    ft_memmove(str, str + 6, 5);  // Copy "World" to the beginning
    assert(strcmp(str, "World World") == 0);  // Check if it worked correctly

    printf("Test 4: (Overlapping memory reverse) Passed\n");
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	printf("All tests passed");
	return(0);
}
*/
