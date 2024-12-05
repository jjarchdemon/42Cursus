/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:05:18 by jambatt           #+#    #+#             */
/*   Updated: 2024/12/05 14:43:46 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdarg.h>
//supporting functions
int     ft_putchar(char c);
int     ft_putstr(const char *str);
int     ft_putnumbr(int nb, int issigned);
int     ft_puthex(unsigned int nb, char letter);
int     ft_putptr(unsigned long long ptr);
//function to chose the formatter
int     pick_formatter(va_list ag, const char formatter);
//main printf
int     ft_printf(const char *s, ...);

#endif
