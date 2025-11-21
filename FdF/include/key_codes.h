/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:14:06 by jambatt           #+#    #+#             */
/*   Updated: 2025/11/20 11:52:38 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H

# ifdef __APPLE__ /* macOS */
/* Movement */
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2

/* Arrows */
#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124

/* Other */
#  define K_ESC 53

/* Event codes (MiniLibX / macOS) */
#  define ON_DESTROY 17
#  define ON_KEYPRESS 2
#  define ON_KEYRELEASE 3

# else
/* Movement */
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100

/* Arrows */
#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363

/* Other */
#  define K_ESC 65307

/* Event codes (X11 / Linux) */
#  define ON_DESTROY 33
#  define ON_KEYPRESS 2
#  define ON_KEYRELEASE 3
# endif

# endif