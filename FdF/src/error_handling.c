/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:59 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:43:02 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	empty_map_error(t_data *data)
{
	perror("Empty map error");
	free_map(data->map);
	free(data);
	exit(1);
}

void	file_error(t_data *data)
{
	perror("Problem with opening file");
	free_map(data->map);
	free(data);
	exit(1);
}

void	allocation_error(t_data *data)
{
	perror("Memory allocation error");
	free_map(data->map);
	free(data);
	exit(1);
}

void	argument_error(void)
{
	perror("please add map path as argument");
	exit(1);
}
