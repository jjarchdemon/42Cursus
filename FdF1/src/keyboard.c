/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:34:47 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 15:23:38 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_keypress(int key, fdf *data)
{
	if (key == ESCAPE)
	{
		ft_close(data);//TODO change name
		exit(0);
	}
	return (0);
}
