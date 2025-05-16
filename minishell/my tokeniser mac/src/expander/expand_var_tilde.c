#include "minishell.h"


void	expand_variable(t_expander *expander, char *str)
{
	char    *value;

	if (*(str + 1) == '?')
		expand_last_status(expander, str);
	else if (expander->context == NO_QUOTE && (*(str + 1) == '\"' || *(str + 1) == '\''))
		return;
	else
	{
		//look for environment variable & assign it to value
		if (!value)
			return ;
		//check for something i dint know
		//add it to buffer
	}
}

void	expand_tilde(t_expander *expander, char *str)
{
   //how to access the home directory
	return;
}


void	expand_last_status(t_expander *expander, char *str)
{
  //how to access the last status
	return; 
}