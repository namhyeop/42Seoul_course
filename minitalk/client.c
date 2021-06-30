/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:49:21 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/29 18:46:33 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void prettysend(int pid, char word, char num)
{
	if(word & num)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send(int pid, char word)
{
	size_t i;
	int pos;

	i = 8;
	pos = 128;
	while (i--)
	{
		prettysend(pid, word, pos);
		pos /= 2;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if(argc == 3)
	{
		pid = ft_atai(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send(pid, argv[2][i]);
			i++;
		}
	}
	return (0);
}
