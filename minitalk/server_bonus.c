/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:14:50 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/30 16:53:26 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	fnstep0(int num, struct __siginfo *ppp, void *pp)
{
	t_node				*ptr;
	struct sigaction	act;

	(void)ppp;
	(void)pp;
	ptr = getinstance();
	ptr->pid.arr[ptr->cnt / 8] <<= 1;
	ptr->pid.arr[ptr->cnt / 8] += (num + 1) % 2;
	ptr->cnt++;
	if (ptr->cnt == 32)
	{
		act.sa_sigaction = fnstep1;
		act.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &act, NULL) != 0)
			exit(1);
		if (sigaction(SIGUSR2, &act, NULL) != 0)
			exit(1);
		ptr -> cnt = 0;
	}
}

void	fnstep1(int num, struct __siginfo *ppp, void *pp)
{
	t_node				*ptr;
	struct sigaction	act;

	(void)ppp;
	(void)pp;
	ptr = getinstance();
	ptr->len.arr[ptr->cnt / 8] <<= 1;
	ptr->len.arr[ptr->cnt / 8] += (num + 1) % 2;
	ptr->cnt++;
	if (ptr->cnt == 32)
	{
		if(!(ptr->str = (char *)malloc(sizeof(char) * ptr->len.num)))
			exit(1);
		act.sa_sigaction =fnstep2;
		act.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &act, NULL) != 0)
			exit(1);
		if (sigaction(SIGUSR2, &act, NULL) != 0)
			exit(1);
		ptr->cnt = 0;
	}
}

void	fnstep2(int num, struct __siginfo *ppp, void *pp)
{
	t_node				*ptr;
	struct sigaction	act;

	(void)ppp;
	(void)pp;
	ptr = getinstance();
	ptr->str[ptr->cnt / 8] <<= 1;
	ptr->str[ptr->cnt / 8] += (num + 1) % 2;
	ptr->cnt++;
	if ((ptr->len.num * 8) == ptr->cnt)
	{
		write(1, ptr->str, ptr->len.num);
		kill(ptr->pid.num, SIGUSR1);
		clean();
		act.sa_sigaction = fnstep0;
		act.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &act, NULL) != 0)
			exit(1);
		if (sigaction(SIGUSR2, &act, NULL) != 0)
			exit(1);
	}
}

int		main(void)
{
	struct sigaction act;

	clean();
	act.sa_sigaction = fnstep0;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		return (-1);
	if (sigaction(SIGUSR2, &act, NULL) != 0)
		return (-1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		usleep(1);
	}
	return (0);
}
