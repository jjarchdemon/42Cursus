/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:40:13 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/27 17:52:53 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test1()
{
    // Test case 1: Compare two equal strings
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    int result1 = ft_strncmp(str1, str2, 5);
    int expected1 = strncmp(str1, str2, 5);
    assert(result1 == expected1);
    printf("Test 1: Passed\n");
}

void test2()
{
    // Test case 2: Compare two different strings
    const char *str3 = "Hello";
    const char *str4 = "World";
    int result2 = ft_strncmp(str3, str4, 5);
    int expected2 = strncmp(str3, str4, 5);
    assert(result2 == expected2);
    printf("Test 2: Passed\n");
}

void test3()
{
    // Test case 3: Compare two strings with n = 0 (always returns 0)
    const char *str5 = "Hello";
    const char *str6 = "World";
    int result3 = ft_strncmp(str5, str6, 0);
    int expected3 = strncmp(str5, str6, 0);
    assert(result3 == expected3);
    printf("Test 3: Passed\n");
}

void test4()
{
    // Test case 4: Compare strings of different lengths
    const char *str7 = "Hello";
    const char *str8 = "Hello, World!";
    int result4 = ft_strncmp(str7, str8, 5);
    int expected4 = strncmp(str7, str8, 5);
    assert(result4 == expected4);
    printf("Test 4: Passed\n");
}

void test5()
{
    // Test case 5: Compare when n exceeds one string length
    const char *str9 = "Short";
    const char *str10 = "Shorter";
    int result5 = ft_strncmp(str9, str10, 7);
    int expected5 = strncmp(str9, str10, 7);
    assert(result5 == expected5);
    printf("Test 5: Passed\n");
}

void test6()
{
    // Test case 6: Compare two empty strings
    const char *str15 = "";
    const char *str16 = "";
    int result6 = ft_strncmp(str15, str16, 0);
    int expected6 = strncmp(str15, str16, 0);
    assert(result6 == expected6);
    printf("Test 6: Passed\n");
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	printf("All tests passed");
}
*/
