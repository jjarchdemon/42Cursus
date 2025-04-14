/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:43:53 by jambatt           #+#    #+#             */
/*   Updated: 2025/04/14 14:43:56 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key_events(int keycode, void *param)
{
	(void) keycode;//delete this
	(void) param;//delete this
	//if (keycode == XK_Escape) uncomment for linux
	//	close_window(param); uncomment for linux
	return (0);
}
