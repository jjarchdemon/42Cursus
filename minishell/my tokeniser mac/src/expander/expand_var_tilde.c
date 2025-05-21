#include "minishell.h"

//the str points to '$'
int	expand_variable(t_expander *expander, char *str, char **envp)
{
	char *var_name;
	char *expanded_variable;
	int expanded_variable_len;

	if (*(str + 1) == '?')
		expand_last_status(expander, str);
	else if (expander->context == NO_QUOTE && (*(str + 1) == '\"' || *(str + 1) == '\''))
		return;//do nothing if its outside a quote or $ is followed by quotes
	else
	{
		if (!1)//if invalid variable name, just return
			return;
		else if (expander->context == NO_QUOTE)//if its outside a quote
			return; //delte, just stand in so code works
			// split $PATH into multiple words (split the variable into words)
		//if valid, 
		char *var_name = get_valid_var_name(str, expander);
		if (!var_name)
		{
			free(var_name);
			return;
		}
		expanded_variable = ft_getenv(envp, var_name);
		if (!expanded_variable)
		{
			free(var_name);
			return;
		}
		expanded_variable_len = ft_strlen(expanded_variable);
		add_expanded_var_to_buffer(expander, expanded_variable, envp);
		free(var_name);
		return (expanded_variable_len);
	}
}

void	add_expanded_var_to_buffer(t_expander *expander, char *expanded_var, char **envp)
{
	int value_len;
	char *new_buf;
	value_len = ft_strlen(expanded_var);
	//allocate new buffer with the size of the old buffer + the size of the value
	new_buf = malloc(sizeof(char) * (expander->buf_size + value_len));
	if (!new_buf)
		return;
	//copy the old buffer contents to the new buffer
	ft_memcpy(new_buf, expander->buf, expander->buf_size);
	ft_memcpy(new_buf + expander->buf_size, expanded_var, value_len);
	//free old buffer and update expander->buf
	free(expander->buf);
	expander->buf = new_buf;
	expander->buf_size += value_len;
	//expander->buf_i += value_len;
}

//buggy, it fucks up when its ~/something
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
		expander->i = -1;//rese
	}
	else
		expander->buf[expander->buf_i++] = *str;
}


void	expand_last_status(t_expander *expander, char *str)
{
  //how to access the last status
	return; 
}

//searches through the provided environment variable array (envp) 
//for the contents of search_term
static char	*ft_getenv(char **envp, char* search_term)
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
//gets correct variable name from the string
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