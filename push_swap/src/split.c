/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:09:30 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/25 17:09:32 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//make every function a single character by using c as anything <= 32 ?
static int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	pos = 0;
	char	*next_word;
	int	len
	int	i;

	len = 0;
	i = 0;
	while (s[pos] == c)
		pos++;
	while (s[pos] && s[pos] != c)
	{
		len++;
		pos++;
	}
	next_word = malloc(len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (s[pos] && s[pos] != c)
		next_word[i++] = s[pos++];
	next_word[i] = '\0';
	return(next_word);
}

char	**split(char *s, char c)
{
	int	word_count;
	char	**array;
	int	i;

	i = 0;
	word_count = count_words(s, c);
	if (!word_count)
		exit (1);
	array = malloc(word_count * sizeof(char *) + 2);
	if (!array)
		return (NULL);
	while (word_count-- >= 0) 
	{
		if (i == 0)
		{
			array[i] = malloc(sizeof(char));
			if (!array[i])
				return (NULL);
			array[i++][0] = '\0';
			continue ;
		}
		array[i++] = get_next_word(s, c);
	}
	array[i] = NULL;
	return (array);
}
