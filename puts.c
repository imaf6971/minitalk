/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:47:57 by erayl             #+#    #+#             */
/*   Updated: 2021/11/27 18:31:48 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == '\v' || *s == '\f' || *s == '\r'))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s && ft_isdigit(*s))
	{
		result *= 10;
		result += *s - '0';
		s++;
	}
	return (result * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
}

void	ft_putpid(pid_t pid)
{
	if (pid > 9)
	{
		ft_putpid(pid / 10);
		ft_putpid(pid % 10);
	}
	else
	{
		ft_putchar(pid + '0');
	}
}
