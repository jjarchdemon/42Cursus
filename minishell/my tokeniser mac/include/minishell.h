/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:52:33 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/16 15:34:11 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>

#define PROMPT "minishell$ "

/*---------------------------- LIBFT_BONUS -----------------------------*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*---------------------------- TOKENISER -----------------------------*/
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

/*---------------------------- PARSER -----------------------------*/

typedef enum e_ast_type
{
	AST_ERROR,
	AST_CMD,
	AST_PIPE,
	AST_REDIRECT_IN,
	AST_REDIRECT_OUT_APP,
	AST_REDIRECT_OUT_TRUNC,
	AST_HEREDOC,
}	t_ast_type;

typedef struct s_ast_node	t_ast_node;

typedef struct s_ast_error
{
	char *invalid_token;
}	t_ast_error;

typedef struct s_ast_cmd
{
	char **args;
}	t_ast_cmd;

typedef struct s_ast_pipe
{
	t_ast_node *left;
	t_ast_node *right;
}	t_ast_pipe;

typedef struct s_ast_redirect
{
	t_token_type type;
	t_ast_node *child;
	char *file;
}	t_ast_redirect;

struct s_ast_node
{
	t_ast_type type;
	union
	{
		t_ast_cmd cmd;
		t_ast_pipe pipe;
		t_ast_redirect redirect;
	} u_data;	//change to just data/content?
};

/*---------------------------- EXPANDER -----------------------------*/

typedef enum e_exp_context
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_exp_context;

typedef struct s_expander
{
	t_exp_context	content;
	int 			i;
	char 			*buf;
	int 			buf_size;
	int 			buf_i;
	t_list			**tokens;
	int 			empty_quotes;
}	t_expander;