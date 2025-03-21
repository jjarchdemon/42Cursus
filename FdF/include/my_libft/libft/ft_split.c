/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:57:34 by jambatt           #+#    #+#             */
/*   Updated: 2024/11/29 15:55:00 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	count;

	if (!s || *s == '\0')
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static const char	*extract_word(const char *s, char c, char **word)
{
	const char	*start;
	size_t		len;

	start = s;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	*word = ft_substr(start, 0, len);
	return (s + len);
}

static void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;

	words = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s = extract_word(s, c, &words[i]);
			if (!words[i])
			{
				free_words(words, i);
				return (NULL);
			}
			i++;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
