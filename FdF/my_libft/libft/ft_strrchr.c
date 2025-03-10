/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:22:06 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/27 17:52:33 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = ft_strlen(s);
	if (uc == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == uc)
			return ((char *)&s[i]);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test1() {
    // Test case 1: Find character in the middle of the string
    const char *str1 = "Hello, World!";
    char ch1 = 'o';
    char *result1 = ft_strrchr(str1, ch1);
    char *expected1 = strrchr(str1, ch1);
    assert(result1 == expected1);
    printf("Test 1 : Passed!\n");
}

void test2() {
    // Test case 2: Character is not found in the string
    const char *str2 = "Hello, World!";
    char ch2 = 'z';
    char *result2 = ft_strrchr(str2, ch2);
    char *expected2 = strrchr(str2, ch2);
    assert(result2 == expected2);
    printf("Test 2 : Passed!\n");
}

void test3()
{
    // Test case 3: Find null terminator '\0' at the end of the string
    const char *str3 = "Hello, World!";
    char ch3 = '\0';
    char *result3 = ft_strrchr(str3, ch3);
    char *expected3 = strrchr(str3, ch3);
    assert(result3 == expected3);
    printf("Test 3 : Passed!\n");
}

void test4()
{
    // Test case 4: Search for character in an empty string
    const char *str4 = "";
    char ch4 = 'a';
    char *result4 = ft_strrchr(str4, ch4);
    char *expected4 = strrchr(str4, ch4);
    assert(result4 == expected4);
    printf("Test 4 : Passed!\n");
}

void test5()
{
    // Test case 5: Character is the first one in the string
    const char *str5 = "apple";
    char ch5 = 'a';
    char *result5 = ft_strrchr(str5, ch5);
    char *expected5 = strrchr(str5, ch5);
    assert(result5 == expected5);
    printf("Test 5 : Passed!\n");
}

void test6()
{
    // Test case 6: Special character
    const char *str6 = "line\nbreak";
    char ch6 = '\n';
    char *result6 = ft_strrchr(str6, ch6);
    char *expected6 = strrchr(str6, ch6);
    assert(result6 == expected6);
    printf("Test 6 : Passed!\n");
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
	return(0);
}
*/
