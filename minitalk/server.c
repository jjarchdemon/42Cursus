/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:11:36 by jambatt           #+#    #+#             */
/*   Updated: 2025/02/24 17:35:25 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int num)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	ft_putchar(c);
}

void	bin2ascii(char *bin_message)
{
	int		j;
	char	byte;

	while (*bin_message)
	{
		byte = 0;
		j = 0;
		while (j < 8)
		{
			byte = byte * 2 + (*bin_message - '0');
			j++;
			bin_message++;
		}
		ft_putchar(byte);
	}
}

void	signal_handler(int sig)
{
	static int	i = 0;
	static char	bin_message[8];

	if (sig == SIGUSR1)
		bin_message[i] = '1';
	else if (sig == SIGUSR2)
		bin_message[i] = '0';
	i++;
	if (i == 8)
	{
		bin2ascii(bin_message);
		i = 0;
	}
}

int	main(void)
{
	int	id;

	id = (int)getpid();
	ft_putnbr(id);
	ft_putchar('\n');
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		sleep(1);
	return (0);
}
