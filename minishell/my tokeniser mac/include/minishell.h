/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:52:33 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/16 11:30:53 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>

#define PROMPT "minishell$ "

typedef struct s_token	t_token;

typedef enum e_token_type
{
	TOKEN_ERROR,			// error
	TOKEN_WORD,				// 1
	TOKEN_PIPE,				// 2
	TOKEN_REDIRECT_IN,		// 3
	TOKEN_REDIRECT_OUT_APP,	// 4
	TOKEN_REDIRECT_OUT_TRUNC,// 5
	TOKEN_HEREDOC,			// 6
	//TOKEN_SUB_OPEN,			// 7 bonus?
	//TOKEN_SUB_CLOSE			// 8 bonus?
}	t_token_type;

struct s_token
{
	char			*content;
	t_token_type	type;
	size_t			len;
	t_token			*next;
};

/*---------------------------- TOKENISER -----------------------------*/
void			del_content(void *content);
int				ft_isspace(char c);
void			ft_lstclear(t_token **lst, void (*del)(void *));
void			ft_lstdelone(t_token *lst, void (*del)(void *));
t_token			*ft_lstlast(t_token *lst);
void			ft_lstadd_back(t_token **lst, t_token *new);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t			ft_strlen(const char *s);
void			get_double_quote_token(char **s, t_token **tokens_ll);
void			get_greater_than_token(char **s, t_token **tokens_ll);
void			get_less_than_token(char **s, t_token **tokens_ll);
void			get_pipe_token(char **s, t_token **tokens_ll);
void			get_single_quote_token(char **s, t_token **tokens_ll);
t_token			*get_token(char *start, char *end);
void			get_word_token(char **s, t_token **tokens_ll);
int				ismeta(char c);
void			print_tokens(t_token *token);
void			skip_whitespace(char **s);
t_token			*tokenize(char *line);
t_token_type	get_token_type(char *line);
t_token_type	get_type_word(char *line);
t_token_type	get_type_pipe(char *line);
t_token_type	get_type_redirectin(char *line);
t_token_type	get_type_redirectout(char *line);

/*---------------------------- EXPANDER -----------------------------*/