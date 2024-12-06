/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:44:21 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/06 17:12:43 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	count;

	count = (int)write(1, &c, 1);
	return (count);
}

int	ft_putstr(const char *str)
{
    int	count;
    
    count = 0;
    if (!str)
    {
        count += ft_putstr("(null)");
        return (count);
    }
    while (*str)
    {
        count += ft_putchar(*str);
        str++;
    }
    return (count);
}
