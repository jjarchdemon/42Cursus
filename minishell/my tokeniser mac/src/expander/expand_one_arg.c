#include "minishell.h"

void	expand_one_arg(char *str, t_list **expanded_args)
{
	t_expander expander;


	init_expander(&expander, str, expanded_args);
	while(*str)
	{
		if (expander.context == NO_QUOTE)
			no_quote_state(&expander, str);
		else if (expander.context == SINGLE_QUOTE)
			single_quote_state(&expander, str);
		else if (expander.context == DOUBLE_QUOTE)
			double_quote_state(&expander, str);
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

/*
no_quote_state() is a traffic cop for the expander
when it's scanning characters that are not inside quotes.
For each character it sees:
	If  ' ', it says "End of a word segment! Add what's in the buffer to the list."
*/
//escaping character logic issue
void	no_quote_state(t_expander *expander, char *str)
{
	if (*str == '~')
		expand_tilde(expander, str);
	else if (*str == '$')
		expand_variable(expander, str);
	else if (*str == ' ')
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

void	single_quote_state(t_expander *expander, char *str)
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
void	double_quote_state(t_expander *expander, char *str)
{
	if (*str == '$')
	{
		//expand variable function
		//add buffer to the linked list 
		// reset the buffer
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
