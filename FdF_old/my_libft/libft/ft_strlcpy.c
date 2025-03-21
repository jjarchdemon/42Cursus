/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:27:08 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/27 18:00:46 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test1()
{
    char dst[20];
    const char *src = "Hello, world!";
    size_t size = 20;

    size_t result = ft_strlcpy(dst, src, size);

    assert(result == strlen(src));   // should be length of source
    assert(strcmp(dst, "Hello, world!") == 0);
    printf("Test 1 (Normal use case): Passed\n");
}

void test2()
{
    char dst[8];  
    const char *src = "Hello, world!";
    size_t size = 8;

    size_t result = ft_strlcpy(dst, src, size);

    assert(result == strlen(src));  // should be the length of source
    assert(strcmp(dst, "Hello, ") == 0);
// Only "Hello, " should be copied (size-1 chars)
    printf("Test 2 (dest is smaller than src): Passed\n"); 
}

void test3()
{
    char dst[14]; 
    const char *src = "Hello, world!";
    size_t size = 14;

    size_t result = ft_strlcpy(dst, src, size);

    assert(result == strlen(src));           // should be the length of source
    assert(strcmp(dst, "Hello, world!") == 0);
    printf("Test 3 (dest is exactly src): Passed\n");
}

void test4() 
{
    char dst[10];
    const char *src = "Test string";
    size_t size = 0;

    size_t result = ft_strlcpy(dst, src, size);

    assert(result == strlen(src));  // should be the length of source
    printf("Test 4 (Size is 0): Passed\n");    
    // The destination should remain unchanged (null-terminated)
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
