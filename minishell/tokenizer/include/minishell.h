/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkolosow <jkolosow@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:52:33 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/12 11:31:35 by jkolosow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>

#define PROMPT "minishell$ "

typedef struct s_token	t_token;

typedef enum e_token_type {
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT_APP,
	TOKEN_REDIRECT_OUT_TRUNC,
	TOKEN_WORD,
	TOKEN_HEREDOC,
	TOKEN_D_QUOTE,
	TOKEN_S_QUOTE,
}	t_token_type;

struct s_token
{
	char			*content;
	t_token_type	type;
	int				fully_quoted;
	size_t			len;
	t_token			*next;
};

void	del_content(void *content);
int		ft_isspace(char c);
void	ft_lstclear(t_token **lst, void (*del)(void *));
void	ft_lstdelone(t_token *lst, void (*del)(void *));
t_token	*ft_lstlast(t_token *lst);
void	ft_lstadd_back(t_token **lst, t_token *new);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlen(const char *s);
void	get_double_quote_token(char **s, t_token **tokens_ll);
void	get_greater_than_token(char **s, t_token **tokens_ll);
void	get_less_than_token(char **s, t_token **tokens_ll);
void	get_pipe_token(char **s, t_token **tokens_ll);
void	get_single_quote_token(char **s, t_token **tokens_ll);
t_token	*get_token(char *start, char *end);
void	get_word_token(char **s, t_token **tokens_ll);
int		ismeta(char c);
void	print_tokens(t_token *token);
void	skip_whitespace(char **s);
t_token	*tokenize(char *line);
