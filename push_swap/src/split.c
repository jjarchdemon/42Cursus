/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:09:30 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/07 14:08:06 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_delimiter(char c)
{
	return (c <= 32);
}

static int	count_words(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_delimiter(*s))
			s++;
		if (*s)
		{
			count++;
			while (*s && !is_delimiter(*s))
				s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, int *pos)
{
	//static int	pos = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[*pos] && is_delimiter(s[*pos]))
		(*pos)++;
	while (s[*pos] && !is_delimiter(s[*pos]))
	{
		len++;
		(*pos)++;
	}
	next_word = malloc(len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	*pos -= len; 
	while (len--)
		next_word[i++] = s[(*pos)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s)
{
	int		word_count;
	char	**array;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	word_count = count_words(s);
	if (!word_count)
		exit(1);
	array = malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < word_count)
	{
		array[i] = get_next_word(s, &pos);
		if (!array[i])
		{
			while (i > 0)
				free(array[--i]);
			free(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
