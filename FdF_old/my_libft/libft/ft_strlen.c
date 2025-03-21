/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:02 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/20 12:40:13 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
/*
#include <stdio.h>
#include <assert.h>
void test1()
{
    char *str = "";
    assert(ft_strlen(str) == 0);
    printf("Test 1 (Empty String): Passed\n");
}
void test2()
{
    char *str = "Hello, World!";
    assert(ft_strlen(str) == 13);
    printf("Test 2 (Non-Empty String): Passed\n");
}
void test3()
{
    char *str = "Hello, \tWorld!\n";
    assert(ft_strlen(str) == 15);
    printf("Test 3 (Special Characters): Passed\n");
}
void test4()
{
    char *str = "1234567890";
    assert(ft_strlen(str) == 10);
    printf("Test 4 (String with Numbers): Passed\n");
}
void test5()
{
    char *str = "Hello, 世界";
    assert(ft_strlen(str) == 13); 
    printf("Test 5 (Non-ASCII Characters): Passed\n");
}
void test6()
{
    char *str = "A";
    assert(ft_strlen(str) == 1);
    printf("Test 6 (Single Character): Passed\n");
}
int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}
*/
