/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkolosow <jkolosow@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:52:03 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/09 11:52:23 by jkolosow         ###   ########.fr       */
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
			printf("token->fully_quoted:\t%d\n", token->fully_quoted);
			printf("token->next:\t[%p]\n", token->next);
			putchar('\n');
			token = token->next;
		}
	}
	return ;
}
