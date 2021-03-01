/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:41:34 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 17:05:23 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	pass_whitespace(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	unsigned long 	result;
	int		sign;

	i = pass_whitespace(str);
	sign = 1;
	if(str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	if(str[i] < '0' || str[i] > '9')
		return 0;
	result = str[i++] - '0';
	while(str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (result >= (unsigned long)LONG_MAX && sign == 1)
		return (-1);
	if (result >= (unsigned long)LONG_MIN && sing == -1)
		return (0);
	result = (int)result;
	return (result * sign);
}
