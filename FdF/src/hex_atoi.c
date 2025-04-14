/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:07 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:44:10 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static int	ft_ishex(char c);
static int	ft_isspace(char c);
static int	get_hex_val(char c);
static void	skip_hex_prefix_if_present(char **str);

int	hex_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str && ft_isspace(*str))
		++str;
	if (*str)
	{
		if (*str == '-')
			sign = -1;
		if ((*str == '-') || (*str == '+'))
			++str;
	}
	skip_hex_prefix_if_present(&str);
	while (*str && ft_ishex(*str))
	{
		result = (result * 16) + get_hex_val(*str);
		++str;
	}
	return (result * sign);
}

static int	ft_ishex(char c)
{
	if (((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f'))
		|| ((c >= 'A') && (c <= 'F')))
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static int	get_hex_val(char c)
{
	c = ft_tolower(c);
	if (ft_isdigit(c))
		return (c - '0');
	else if ((c >= 'a') && (c <= 'f'))
		return (c - 'a' + 10);
	else
		return (0);
}

static void	skip_hex_prefix_if_present(char **str)
{
	char	*ptr;

	if (!str || *str == NULL)
		return ;
	ptr = *str;
	if ((*ptr && (*ptr == '0'))
		&& ((*(++ptr)) && ((*ptr == 'x') || (*ptr == 'X'))))
		*str += 2;
	return ;
}
*/
int hex_atoi(char *str)
{
    int result = 0;
    char c;
	int sign = 1;
	if (!str)
		return 0;
    // Skip optional "0x" or "0X" prefix
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        str += 2;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
    while ((c = *str++))
    {
        result *= 16;
        if (c >= '0' && c <= '9')
            result += c - '0';
        else if (c >= 'a' && c <= 'f')
            result += c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            result += c - 'A' + 10;
        else
            break; // Stop on invalid character
    }

    return result * sign;
}