#include "minishell.h"

void    init_expander(t_expander *expander, char *str, t_list**expanded_args)
{
    expander->context = NO_QUOTE;
    expander->i = 0;
    expander->buf = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!expander->buf)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    expander->buf_size = ft_strlen(str) + 1;
    expander->buf_i = 0;
    expander->tokens = expanded_args;
    expander->empty_quotes = 0;
}
