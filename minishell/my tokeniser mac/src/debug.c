/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:52:03 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/15 21:19:29 by joseph           ###   ########.fr       */
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
			printf("token->type:\t%d\n", token->type);
			printf("token->len:\t%zu\n", token->len);
			//printf("token->next:\t[%p]\n", token->next);
			putchar('\n');
			token = token->next;
		}
	}
	return ;
}
