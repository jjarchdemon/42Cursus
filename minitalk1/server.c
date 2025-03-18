/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:11:36 by jambatt           #+#    #+#             */
/*   Updated: 2025/02/25 14:00:02 by jambatt          ###   ########.fr       */
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

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static t_signal_state	state;
	int						received_bit;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		received_bit = 1;
	else 
		received_bit = 0;
	state.current_char = (state.current_char << 1) | received_bit;
	state.bit_count++;
	if (state.bit_count == 8)
	{
		ft_putchar(state.current_char);
		state.current_char = 0;
		state.bit_count = 0;
	}
}

int	main(void)
{
	int					id;
	struct sigaction	sa;

	id = (int)getpid();
	ft_putnbr(id);
	ft_putchar('\n');
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putchar('e');
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putchar('e');
		return (1);
	}
	while (1)
		pause();
	return (0);
}
