/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:11:25 by jambatt           #+#    #+#             */
/*   Updated: 2025/02/24 18:31:06 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//putstr
void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

//convert from str to num
int	ft_atoi(const char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num);
}

//convert from ascii to bit and transmit  
//sigpos=significant position/place value
void	conv_n_transmit(const char *message, int server_pid)
{
	int		sigpos;
	char	letter;

	while (*message)
	{
		sigpos = 128;
		letter = *message;
		while (sigpos > 0)
		{
			if (letter >= sigpos)
			{
				kill(server_pid, SIGUSR1);
				letter -= sigpos;
			}
			else
				kill(server_pid, SIGUSR2);
			sigpos /= 2;
			usleep(100);
		}
		message++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_putstr("Please input the correct no. of arg\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
	{
		ft_putstr("PID cannot be negativ\n");
		return (1);
	}
	conv_n_transmit(argv[2], server_pid);
	return (0);
}
