/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:55:44 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/29 18:06:39 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subtool.h"

void		writenbr(int n, int fd)
{
	size_t	i;
	char	nbr[11];

	i = 11;
	while(i-- >= 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		if (n == 0)
		{
			while(i <= 10)
			{
				write(fd, &nbr[i], 1);
				i++;
			}
			break;
		}
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if(n < 0)
	{
		write(fd, "-", 1);
		n *- -1;
	}
	writenbr(n, fd);
}
