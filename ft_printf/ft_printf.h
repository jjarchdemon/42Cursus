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
//support functions (strs and ptrs)
int	ft_putchar(char c);
int	ft_putstr(const char *str);
//hexptr functions
int	ft_puthex(unsigned long nb, char letter);
int	ft_putptr(void *ptr);
//nbr functions
int	ft_putnumbr(int nb);
int	ft_putunumbr(unsigned int nb);

//function to chose the formatter
int	pick_formatter(va_list ag, const char formatter);
//main printf
int	ft_printf(const char *s, ...);

#endif
