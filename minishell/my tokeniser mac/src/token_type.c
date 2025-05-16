//header here

#include "minishell.h"

t_token_type	get_type_pipe(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line == '|')
	{
		len++;
		line++;
	}
	if (len == 1)
		return (TOKEN_PIPE);
	return (TOKEN_ERROR);
}

t_token_type	get_type_redirectin(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line == '<')
	{
		len++;
		line++;
	}
	if (len == 1)
		return (TOKEN_REDIRECT_IN);
	else if (len == 2)
		return (TOKEN_HEREDOC);
	return (TOKEN_ERROR);
}

t_token_type	get_type_redirectout(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line == '>')
	{
		len++;
		line++;
	}
	if (len == 1)
		return (TOKEN_REDIRECT_OUT_TRUNC);
	else if (len == 2)
		return (TOKEN_REDIRECT_OUT_APP);
	return (TOKEN_ERROR);
}

/*
t_token_type	get_type_subshell(char *line)
{
	if (*line == '(')
		return (TOKEN_SUB_OPEN);
	else if (*line == ')')
		return (TOKEN_SUB_CLOSE);
	return (TOKEN_ERROR);
}*/

t_token_type	get_type_word(char *line)
{
	char	c;
	int		in_quote;

	in_quote = 0;
	while (*line)
	{
		if (*line && *(line + 1) == '\\')
			line++;//or line += 2;
		else if (*line == '\"' || *line == '\'')
		{
			if (in_quote == 0)
			{
				in_quote = 1;
				c = *line;
			}
			else if (in_quote == 1 && c == *line)
				in_quote = 0;
		}
		else if ((ismeta(*line) || ft_isspace(*line)) && in_quote == 0)
			break ;
		line++;
	}
	if (in_quote == 1)
		return (TOKEN_ERROR);
	return (TOKEN_WORD);
}
