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

void	print_empty_map(t_data *data)
{
	ft_putstr_fd("Map error: map is empty\n", 2);
	free_map(data->map);
	free(data);
	exit(1);
}

void	print_file_error(t_data *data)
{
	ft_putstr_fd("File error: could not open / read file\n", 2);
	free_map(data->map);
	free(data);
	exit(1);
}

void	print_memory_error(t_data *data)
{
	ft_putstr_fd("Memory error: could not allocate sufficent memory\n", 2);
	free_map(data->map);
	free(data);
	exit(1);
}

void	print_usage_message(void)
{
	ft_putstr_fd("Usage: ./fdf <filename>\n", 2);
	exit(1);
}
