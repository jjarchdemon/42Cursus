/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkolosow <jkolosow@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:54:59 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/09 11:45:02 by jkolosow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tokenize(char *line)
{
	t_token	*tokens_ll;

	tokens_ll = NULL;
	if (*line == '\0')
		return (NULL);
	while (*line)
	{
		skip_whitespace(&line);
		if (*line)
		{
			if (*line == '|')
				get_pipe_token(&line, &tokens_ll);
			else if (*line == '<')
				get_less_than_token(&line, &tokens_ll);
			else if (*line == '>')
				get_greater_than_token(&line, &tokens_ll);
			else if (*line == '"')
				get_double_quote_token(&line, &tokens_ll);
			else if (*line == '\'')
				get_single_quote_token(&line, &tokens_ll);
			else
				get_word_token(&line, &tokens_ll);
		}
	}
	return (tokens_ll);
}

t_token	*get_token(char *start, char *end)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = malloc((end - start) + 1 * sizeof (char));
	if (!(token->content))
	{
		free(token);
		return (NULL);
	}
	ft_strlcpy(token->content, start, end - start + 1);
	token->fully_quoted = 0;
	token->len = end - start;
	token->next = NULL;
	return (token);
}
