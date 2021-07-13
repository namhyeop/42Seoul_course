/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:24 by namhkim           #+#    #+#             */
/*   Updated: 2021/07/07 15:44:25 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdio.h>

void	bit_send(int pid, char word, char num)
{
	if (word & num)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1000);
}

void	send_unit(int pid, char word)
{
	size_t	i;

	i = 128;
	while (i > 0)
	{
		bit_send(pid, word, (int)i);
		i /= 2;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_unit(pid, argv[2][i]);
			i++;
		}
	}
	return (0);
}
