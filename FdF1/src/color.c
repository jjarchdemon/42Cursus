/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:34:13 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 11:56:37 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stddef.h>  //for count_words

unsigned int get_color(int z1, int z2)
{
    float	blend_ratio;
    int	red;
    int	green;

    blend_ratio = (((z1 + z2) / 2.0) + 30.0) / 110.0;
    red = (int)(blend_ratio * 255);
    green = (int)((1 - blend_ratio) * 255);
    return ((red << 16) | (green << 8) | 150);
}

//TODO delete this shit, figure it out
size_t count_words(char const *s, char c) {
    size_t count = 0;
    int in_word = 0;

    // Traverse through the string
    while (*s) {
        if (*s != c && !in_word) {
            // Start of a new word
            in_word = 1;
            count++;
        } else if (*s == c) {
            // We are at a separator, mark that we're not in a word
            in_word = 0;
        }
        s++;
    }

    return count;
}

