/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_formatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:07:13 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/06 14:43:48 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pick_formatter(va_list ag, const char formatter)
{
	int	count;

	count = 0;
	if (formatter == 'c')
		count += ft_putchar(va_arg(ag, int));
	else if (formatter == 's')
		count += ft_putstr(va_arg(ag, const char *));
	else if (formatter == 'p')
		count += ft_putptr(va_arg(ag, void *));
	else if (formatter == 'd' || formatter == 'i')
		count += ft_putnumbr(va_arg(ag, int));
	else if (formatter == 'u')
		count += ft_putunumbr(va_arg(ag, unsigned int));
	else if (formatter == 'x')
		count += ft_puthex(va_arg(ag, unsigned long), 'a');
	else if (formatter == 'X')
		count += ft_puthex(va_arg(ag, unsigned long), 'A');
	else if (formatter == '%')
		count += ft_putchar('%');
	else
		return (-1);
	return (count);
}
