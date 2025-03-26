/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:19:32 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/27 18:02:19 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

void test()
{
    // Test case 1: Basic test - Character found in the memory block
    const char *str1 = "Hello, World!";
    int c1 = 'o';
    void *result1 = ft_memchr(str1, c1, 13);  // Searching in the entire string
    void *expected1 = memchr(str1, c1, 13);
    assert(result1 == expected1);
    printf("Test 1: Passed\n");

    // Test case 2: Character not found in the memory block
    const char *str2 = "Hello, World!";
    int c2 = 'z';
    void *result2 = ft_memchr(str2, c2, 13);  // Searching for 'z' in the string
    void *expected2 = memchr(str2, c2, 13);
    assert(result2 == expected2);
    printf("Test 2: Passed\n");

    // Test case 3: Searching within a smaller block of memory
    const char *str3 = "Hello, World!";
    int c3 = 'o';
    void *result3 = ft_memchr(str3, c3, 5);  
// Searching only in the first 5 characters ("Hello")
    void *expected3 = memchr(str3, c3, 5);
    assert(result3 == expected3);
    printf("Test 3: Passed\n");

    // Test case 4: Search in an empty memory block
    const char *str4 = "";
    int c4 = 'H';
    void *result4 = ft_memchr(str4, c4, 0);  // No characters to search in
    void *expected4 = memchr(str4, c4, 0);
    assert(result4 == expected4);
    printf("Test 4: Passed\n");

    printf("All tests passed!\n");
}

int main() {
    test();
    return 0;
}
*/
