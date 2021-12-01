/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:20:24 by erayl             #+#    #+#             */
/*   Updated: 2021/11/27 21:39:49 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_tmp;

char	bit_shift(void)
{
	static char	bs = (sizeof(char) * 8 - 1);

	if (bs == 0)
	{
		bs = (sizeof(char) * 8 - 1);
		return (0);
	}
	else
		return (bs--);
}

void	bit_hnd(int bit)
{
	char	bs;

	bs = bit_shift();
	g_tmp |= bit << bs;
	if (bs == 0)
	{
		write(1, &g_tmp, 1);
		g_tmp = 0;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		bit_hnd(1);
	else if (signum == SIGUSR2)
		bit_hnd(0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	g_tmp = 0;
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	write(1, "PID: ", 5);
	ft_putpid(pid);
	write(1, "\n", 1);
	while (1)
		;
}
