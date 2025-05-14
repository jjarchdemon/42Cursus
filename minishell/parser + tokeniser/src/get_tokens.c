/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkolosow <jkolosow@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:59:51 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/12 11:44:52 by jkolosow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_double_quote_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	*s += 1;
	while (**s && **s != '"')
		*s += 1;
	if (**s && **s == '"')
		*s += 1;
	end = *s;
	token = get_token(start, end);
	token->type = TOKEN_D_QUOTE;
	if (token->len > 1 && token->content[token->len - 1] == '"')
		token->fully_quoted = 1;
	// else
	// 	token->fully_quoted = 0;
	ft_lstadd_back(tokens_ll, token);
}

void	get_word_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	while (**s && !ft_isspace(**s) && !ismeta(**s))
		*s += 1;
	end = *s;
	token = get_token(start, end);
	token->type = TOKEN_WORD;
	ft_lstadd_back(tokens_ll, token);
}

void	get_single_quote_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	*s += 1;
	while (**s && **s != '\'')
		*s += 1;
	if (**s && **s == '\'')
		*s += 1;
	end = *s;
	token = get_token(start, end);
	token->type = TOKEN_S_QUOTE;
	if (token->len > 1 && token->content[token->len - 1] == '\'')
		token->fully_quoted = 1;
	// else
	// 	token->fully_quoted = 0;
	ft_lstadd_back(tokens_ll, token);
}

void	get_pipe_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	*s += 1;
	end = *s;
	token = get_token(start, end);
	token->type = TOKEN_PIPE;
	ft_lstadd_back(tokens_ll, token);
}

void	get_greater_than_token(char **s, t_token **tokens_ll)
{
	int		ttype;
	char	*start;
	char	*end;
	t_token	*token;

	ttype = 0;
	start = *s;
	*s += 1;
	if (**s && **s == '>')
	{
		ttype = 1;
		*s += 1;
	}
	end = *s;
	token = get_token(start, end);
	if (ttype == 1)
		token->type = TOKEN_REDIRECT_OUT_APP;
	else
		token->type = TOKEN_REDIRECT_OUT_TRUNC;
	ft_lstadd_back(tokens_ll, token);
}

void	get_less_than_token(char **s, t_token **tokens_ll)
{
	int		ttype;
	char	*start;
	char	*end;
	t_token	*token;

	ttype = 0;
	start = *s;
	*s += 1;
	if (**s && **s == '<')
	{
		ttype = 1;
		*s += 1;
	}
	end = *s;
	token = get_token(start, end);
	if (ttype == 1)
		token->type = TOKEN_HEREDOC;
	else
		token->type = TOKEN_REDIRECT_IN;
	ft_lstadd_back(tokens_ll, token);
}
