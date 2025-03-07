/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:44:22 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/28 16:59:54 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
	//ft_strlcpy(dst + dst_len, src, size - dst_len);
	//dst[size - 1] = '\0';
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test1() {
    char dst[20] = "Hello, ";
    const char *src = "world!";
    size_t size = 20;  

    size_t result = ft_strlcat(dst, src, size);

    assert(result == strlen("Hello, world!"));  
// The return value should be the total length of the concatenated string
    assert(strcmp(dst, "Hello, world!") == 0);  
// The destination should contain the full concatenated string
	printf("Test 1: Passed\n");
}

void test2() {
    char dst[10] = "Hello, ";
    const char *src = "world!";
    size_t size = 0;  // Zero size, no space for concatenation

    size_t result = ft_strlcat(dst, src, size);

    assert(result == strlen("world!"));  
// The return value should be the length of the source string
    assert(strcmp(dst, "Hello, ") == 0);  
// The destination should remain unchanged
	printf("Test 2: Passed\n");
}

void test3() {
    char dst[20] = "Hello, ";
    const char *src = "";
    size_t size = 20;  // Large enough space to handle the concatenation

    size_t result = ft_strlcat(dst, src, size);

    assert(result == strlen("Hello, "));  
// The return value should be the length of the destination string
    assert(strcmp(dst, "Hello, ") == 0);  
// The destination should remain unchanged
	printf("Test 3: Passed\n");
}

void test4() {
    char dst[20] = "";
    const char *src = "world!";
    size_t size = 20;  // Enough space to hold the source string

    size_t result = ft_strlcat(dst, src, size);

    assert(result == strlen("world!"));  
// The return value should be the length of the source string
    assert(strcmp(dst, "world!") == 0);  
// The destination should now hold the source string
	printf("Test 4: Passed\n");
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	printf("All tests passed");
	return (0);
}
*/
