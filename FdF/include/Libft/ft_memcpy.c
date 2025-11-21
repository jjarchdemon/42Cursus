/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:39:51 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/27 14:34:14 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (!dest && !src)
		return (dest);
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test1() {
    char src[] = "Hello";
    char dest1[6], dest2[6];

    ft_memcpy(dest1, src, 6);  // Copy including the null terminator
    memcpy(dest2, src, 6);

    assert(strcmp(dest1, dest2) == 0);  // Compare if both are the same
    printf("Test 1 (Basic memcpy): Passed\n");
}

void test2()
{
    char src[] = "Hello";
    char dest1[6] = {0}, dest2[6] = {0};

    ft_memcpy(dest1, src, 0);  // Copy zero bytes
    memcpy(dest2, src, 0);

    // Both destination arrays should remain unchanged
    assert(strcmp(dest1, dest2) == 0);
    printf("Test 2 (Zero bytes): Passed\n");
}

void test3() {
    char str[] = "Hello World";
    // Copying a part of the string to a new location in the string
    ft_memcpy(str + 6, str, 5);  		// Copy "Hello" to "World"
    assert(strcmp(str, "Hello Hello") == 0);  	// Check if it worked correctly

    printf("Test 3 (Overlapping memory) Passed\n");
}

int main()
{
	test1();
	test2();
	test3();
	printf("All tests passed.");
	return(0);
}
*/
