/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:50:29 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 02:50:29 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int		get_len(int n)
{
	int			len;
	long long	n2;

	len = 0;
	n2 = (long long)n;
	if (n2 < 0)
	{
		len++;
		n2 *= -1;
	}
	while (n2 >= 10)
	{
		len++;
		n2 /= 10;
	}
	len++;

	return (len);
}

char			*ft_itoa(int n)
{
	int			len;
	int			i;
	long long	n2;
	char		*result;

	len = get_len(n);
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	result[len] = 0;
	i = 0;
	n2 = n < 0 ? (long long)n * -1 : (long long)n;
	while (i < len)
	{
		if (i == len - 1 && n < 0)
		{
			result[0] = '-';
			break;
		}
		result[len - i - 1] = n2 % 10 + '0';
		n2 /= 10;
		i++;
	}
	return (result);
}
