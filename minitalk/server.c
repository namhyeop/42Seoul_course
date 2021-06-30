/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:30:00 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/30 14:45:07 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	fnsig(int num)
{
	static	char	word = 0;
	static	int		cnt = 0;

	word <<= 1;
	word += (num + 1) % 2;
	cnt++;
	if (cnt == 8)
	{
		write(1, &word, 1);
		word = 0;
		cnt = 0;
	}
	usleep(1);
}

int		main(void)
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
