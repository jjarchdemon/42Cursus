/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkolosow <jkolosow@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:23:10 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/11 13:27:48 by jkolosow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TO DO'S
	- get token could return NULL; in that case the token_ll should be freed and
		an error message should be printed
*/

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_token	*token_ll;

	(void) argc;
	(void) argv;
	(void) envp;
	line = NULL;
	while (1)
	{
		line = readline(PROMPT);
		if (line == NULL)
			exit(EXIT_SUCCESS);
		printf("line\t->\t'%s'\n", line);
		token_ll = tokenize(line);
		// add_history(line);
		free(line);
		line = NULL;
		print_tokens(token_ll);
		ft_lstclear(&token_ll, del_content);
	}
	return (EXIT_SUCCESS);
}
