/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:00:32 by erayl             #+#    #+#             */
/*   Updated: 2021/11/27 21:44:19 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	counter;

	counter = 1 << (sizeof(char) * 8 - 1);
	while (counter)
	{
		if (c & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Can't send signal by PID, terminating client\n", 45);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Can't send signal by PID, terminating client\n", 45);
				exit(1);
			}
		}
		counter >>= 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc == 3)
	{
		spid = ft_atoi(argv[1]);
		while (*argv[2] != '\0')
		{
			send_char(spid, *argv[2]);
			argv[2]++;
		}
	}
	else
		write(1, "usage: ./client [SERVER_PID] [MESSAGE]\n", 39);
}
