/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:52:03 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/16 11:14:51 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *token)
{
	if (token == NULL)
		printf("There are no tokens\n");
	else
	{
		while (token)
		{
			printf("token->content:\t'%s'\n", token->content);
			if (token->type == TOKEN_ERROR)
				printf("token->type:\tTOKEN_ERROR\n");
			else if (token->type == TOKEN_WORD)
				printf("token->type:\tTOKEN_WORD\n");
			else if (token->type == TOKEN_PIPE)
				printf("token->type:\tTOKEN_PIPE\n");
			else if (token->type == TOKEN_REDIRECT_IN)
				printf("token->type:\tTOKEN_REDIRECT_IN\n");
			else if (token->type == TOKEN_REDIRECT_OUT_APP)
				printf("token->type:\tTOKEN_REDIRECT_OUT_APP\n");
			else if (token->type == TOKEN_REDIRECT_OUT_TRUNC)
				printf("token->type:\tTOKEN_REDIRECT_OUT_TRUNC\n");
			else if (token->type == TOKEN_HEREDOC)
				printf("token->type:\tTOKEN_HEREDOC\n");
			printf("token->len:\t%zu\n", token->len);
			//printf("token->next:\t[%p]\n", token->next);
			putchar('\n');
			token = token->next;
		}
	}
	return ;
}
