/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:06 by namhkim           #+#    #+#             */
/*   Updated: 2021/07/07 15:44:07 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	fnsig(int sig)
{
	static char	word = 0;
	static int	cnt = 0;

	word <<= 1;
	if (sig == 30)
		word += 1;
	cnt++;
	if (cnt == 8)
	{
		write(1, &word, 1);
		word = 0;
		cnt = 0;
	}
	usleep(1);
}

int	main(void)
{
	signal(SIGUSR1, (void *)fnsig);
	signal(SIGUSR2, (void *)fnsig);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
