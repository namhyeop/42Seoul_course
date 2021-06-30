/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:48:41 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/30 16:00:19 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int		*getinstance(void)
{
	static int finished;

	finished = 1;
	return (&finished);
}

void	fnsig1(void)
{
	write(1, "Error of send\n", 21);
	*(getinstance()) = 0;
}

int		main(int argc, char **argv[])
{
	union u_data	mypid;
	union u_data	len;
	pid_t			pid;
	int				i;

	signal(SIGUSR1, (void *)fnsig1);
	if (argc == 3)
	{
		mypid.pid = getpid();
		pid = ft_atoi(argv[1]);
		len.pid = ft_strlen(argv[2]);
		i = 0;
		while (i < 4)
			send(pid, mypid.arr[i++]);
		usleep(200);
		i = 0;
		while (i < 4)
			send(pid, len.arr[i++]);
		i = 0;
		while (argv[2][i])
			send(pid, argv[2][i++]);
		while (*getinstance())
			usleep(1);
	}
	return (0);
}
