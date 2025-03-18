/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:16:56 by jambatt           #+#    #+#             */
/*   Updated: 2025/02/24 14:37:10 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>		//for the signals duh
# include <unistd.h>		//for write/ usleep()
# include <limits.h>		//for INT_MAX
# include <sys/types.h>		//for pid

typedef struct s_signal_state
{
	int		bit_count;
	char	current_char;
}	t_signal_state;

#endif
