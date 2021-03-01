/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:48:07 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 00:54:54 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, int n)
{
	unsigned char	tmpS1;
	unsigned char	tmpS2;
	int		i;

	if(n == 0)
		return (0);
	tmpS1 = (unsigned char *)s1;
	tmpS2 = (unsigned char *)s2;
	i = 0;
	while(i < n)
	{
		if(tmpS1[i] != tmpS2[i])
			return (tmpS1[i] - tmpS2[i]);
		i++;
	}
	return (0);
}

