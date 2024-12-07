/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:05:18 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/06 15:21:11 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
//support functions
//(strs and chars)
int	ft_putchar(int c);
int	ft_putstr(const char *str);
//(hex and ptr)
int	ft_puthex(unsigned long nb, char letter);
int	ft_putptr(void *ptr);
//nbr functions
int	ft_putnumbr(long nb);

//function to chose the formatter
int	pick_formatter(va_list ag, const char formatter);
//main printf
int	ft_printf(const char *s, ...);

#endif
