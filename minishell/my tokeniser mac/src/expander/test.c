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

void no_quote_state(t_expander *expander, char *str);
void single_quote_state(t_expander *expander, char *str);
void double_quote_state(t_expander *expander, char *str);

void expand_one_arg(char *str, t_list **expanded_args)
{
    t_expander expander;

    init_expander(&expander, str, expanded_args); //initialize the expander
    while(*str)
    {
        if (expander.context == NO_QUOTE)
            no_quote_state(&expander, str);
        else if (expander.context == SINGLE_QUOTE)
            single_quote_state(&expander, str);
        else if (expander.context == DOUBLE_QUOTE)
            double_quote_state(&expander, str);
        printf("insert: -|%c|-\n", expander.buf[expander.buf_i-1]);
        if (*str)//should there be a check here that it is still *str 
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
    printf("the buffer: -|%s|-\n", expander.buf);
}

void no_quote_state(t_expander *expander, char *str)
{
    //int index;

    if (*str == '~')
    {
        //add the buffer to the linked list
        //reset the buffer
        str++;
    }
    else if (*str == '$')
    {
        //expand variable function
        //add the buffer to the linked list
        //reset the buffer
        str++;
    }
    else if (*str == ' ')
    {
        //function to add the buffer to the linked list
        //reset the buffer
        str++;
    }
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
        //add the character to the buffer
        expander->buf[expander->buf_i] = *str;
        expander->buf_i++;
        //str++;
    }
}
void single_quote_state(t_expander *expander, char *str)
{
    if (*str == '\'')
        expander->context = NO_QUOTE;
    else
    {
        expander->buf[expander->buf_i] = *str;
        expander->buf_i++;
    } 
}
void double_quote_state(t_expander *expander, char *str)
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
int main (void)
{
    char *str = "ab\'c";
    t_list *expanded_args = NULL;

    expand_one_arg(str, &expanded_args);
    return (0);
}
