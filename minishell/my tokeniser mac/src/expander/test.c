/*-------------------------------HEADER PART-----------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
typedef enum e_exp_context
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_exp_context;
typedef struct s_expander
{
	t_exp_context	context;
	int 			i;
	char 			*buf;
	int 			buf_size;
	int 			buf_i;
	t_list			**tokens;
	int 			empty_quotes;
}	t_expander;

size_t	ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_isalpha(int c);
int		ft_alnum(int c);
char	*ft_getenv(char **envp, char* search_term);
void	init_expander(t_expander *expander, char *str, t_list**expanded_args);
void	expand_one_arg(char *str, t_list **expanded_args, char **envp);
void	no_quote_state(t_expander *expander, char *str, char **envp);
void	single_quote_state(t_expander *expander, char *str, char **envp);
void	double_quote_state(t_expander *expander, char *str, char **envp);
void	add_expanded_var_to_buffer(t_expander *expander, char *expanded_var, char **envp);
int		expand_variable(t_expander *expander, char *str, char **envp);
void	expand_tilde(t_expander *expander, char *str, char **envp);
char	*get_valid_var_name(char *str, t_expander *expander);
/*-------------------------------HEADER END-----------------------------------*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	return (len);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = dest;
	while (n > 0)
	{
		*dest_ptr = *((char *)src);
		++dest_ptr;
		++src;
		--n;
	}
	return (dest);
}
int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ft_alnum(int c)
{
    return ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'));
}
char	*ft_getenv(char **envp, char* search_term)
{
	int			i;
	size_t		len;

	i = 0;
	len = ft_strlen(search_term);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], search_term, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}
void init_expander(t_expander *expander, char *str, t_list**expanded_args)
{
    expander->context = NO_QUOTE;
    expander->i = 0;
    expander->buf = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!expander->buf)
    {
        perror("malloc");
        exit(1);
    }
    expander->buf_size = ft_strlen(str) + 1;
    expander->buf_i = 0;
    expander->tokens = expanded_args;
    expander->empty_quotes = 0;
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t	i;

    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}
void	expand_one_arg(char *str, t_list **expanded_args, char **envp)
{
	t_expander expander;


	init_expander(&expander, str, expanded_args);
	while(*str)
	{
		if (expander.context == NO_QUOTE)
			no_quote_state(&expander, str, envp);
		else if (expander.context == SINGLE_QUOTE)
			single_quote_state(&expander, str, envp);
		else if (expander.context == DOUBLE_QUOTE)
			double_quote_state(&expander, str, envp);
		if (*str)
			str++;
	}
	if (expander.context != NO_QUOTE)
	{
		printf("quote is not closed\n");
		//free the allocated memory in expander
		exit(1);
	}
	//function to add the buffer to the linked list
	//debug fn to print the linked list
	printf("the buffer: %s\n", expander.buf);
}

//escaping character still needs to be handled
void	no_quote_state(t_expander *expander, char *str, char **envp)
{
	int  expanded_variable_len = 0;

	if (*str == '~')
		expand_tilde(expander, str, envp);
	else if (*str == '$')
	{
		expanded_variable_len = expand_variable(expander, str, envp);
		str += expanded_variable_len;
	}
	else if (*str == ' ')
		return;
		//function to add the buffer to the linked list
		//reset the buffer
	else if (*str == '\"')
		expander->context = DOUBLE_QUOTE;
	else if (*str == '\'')
		expander->context = SINGLE_QUOTE;
	else if (*str == '\\')
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
		str++;
	}
	else
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	}
}

void	single_quote_state(t_expander *expander, char *str, char **envp)
{
	if (*str == '\'')
		expander->context = NO_QUOTE;
	else
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	} 
}
//escaping character still needs to be handled
void	double_quote_state(t_expander *expander, char *str, char **envp)
{
	int  expanded_variable_len = 0;
	if (*str == '$')
	{
		expanded_variable_len = expand_variable(expander, str, envp);
		str += expanded_variable_len;
	}
	else if (*str == '\"')
		expander->context = NO_QUOTE;
	else if (*str == '\\' && (*(str + 1) == '\"' || *(str + 1) == '\\'))
	{
		str++;
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	}
	else
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	}
}
void	add_expanded_var_to_buffer(t_expander *expander, char *expanded_var, char **envp)
{
    int value_len = ft_strlen(expanded_var);
    int buf_len = ft_strlen(expander->buf);
    int new_size = buf_len + value_len + 1;
    char *new_buf = malloc(new_size);

    if (!new_buf)
        return;
    ft_memcpy(new_buf, expander->buf, buf_len);
    ft_memcpy(new_buf + buf_len, expanded_var, value_len);
    new_buf[buf_len + value_len] = '\0';
    free(expander->buf);
    expander->buf = new_buf;
    expander->buf_size = new_size;
}
int	expand_variable(t_expander *expander, char *str, char **envp)
{
    char *var_name;
    char *expanded_variable;
    int var_name_len;

    if (*(str + 1) == '?')
        return 2; // "$?" is 2 chars
    else if (expander->context == NO_QUOTE && (*(str + 1) == '\"' || *(str + 1) == '\''))
        return 1;
    else
    {
        var_name = get_valid_var_name(str, expander);
        if (!var_name)
            return 1;
        expanded_variable = ft_getenv(envp, var_name);
        if (expanded_variable)
            add_expanded_var_to_buffer(expander, expanded_variable, envp);
        var_name_len = ft_strlen(var_name);
        free(var_name);
        return var_name_len + 1; // +1 for the '$'
    }
}
void	expand_tilde(t_expander *expander, char *str, char **envp)
{
	char	*home;

	home = NULL;
	// Check if it's "~" or "~/..."
	if (*(str + 1) == '/' || *(str + 1) == '\0')
	{
		while (*envp)
		{
			if (ft_strncmp(*envp, "HOME=", 5) == 0)
			{
				home = *envp + 5;
				break ;
			}
			envp++;
		}
		if (!home)
			return ;
		while (*home)
			expander->buf[expander->buf_i++] = *home++;
		str++;
		while (*str)
			expander->buf[expander->buf_i++] = *str++;
	}
	else
		expander->buf[expander->buf_i++] = *str;
}
char *get_valid_var_name(char *str, t_expander *expander)
{
	char *var_name;
	int var_len;

	var_len = 0;
	str++;//skip the $
	if (!ft_isalpha(*str) && *str != '_')//get ft_isalpha from libft
		return (NULL);
	while (ft_alnum(*str) || *str == '_')//get ft_alnum from libft
	{
		str++;
		var_len++;
	}
	str = str - var_len; //reset str to the start of the variable name
	var_name = malloc(sizeof(char) * (var_len + 1));
	if (!var_name)
		return (NULL);
	ft_memcpy(var_name, str, var_len);
	var_name[var_len] = '\0';
	return (var_name);
}
int main (int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;

    char *str = "$DISPLAY $ZSH";
    t_list *expanded_args = NULL;

    expand_one_arg(str, &expanded_args, envp);
    return (0);
}
