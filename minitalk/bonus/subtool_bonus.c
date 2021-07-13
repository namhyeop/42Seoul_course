/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtool_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:46:32 by namhkim           #+#    #+#             */
/*   Updated: 2021/07/07 15:46:33 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subtool_bonus.h"

void	writenbr(int n, int fd)
{
	size_t			i;
	char			nbr[11];

	i = 11;
	while (i-- >= 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		if (n == 0)
		{
			while (i <= 10)
			{
				write(fd, &nbr[i], 1);
				i++;
			}
			break ;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	writenbr(n, fd);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	result;
	int				sign;

	i = 0;
	while (*str >= 9 & *str <= 13 || *str == 32)
		i++;
	sign = 1;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	result = str[i++] - '0';
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (result >= (unsigned long)LONG_MAX && sign == 1)
		return (-1);
	if (result >= (unsigned long)LONG_MIN && sign == -1)
		return (0);
	result = (int)result;
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
