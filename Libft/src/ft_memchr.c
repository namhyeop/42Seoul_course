/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:44:18 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 21:34:37 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	int	i;
	unsigned char	*s2;
	unsigned char	c2;

	s2 = (unsigned char)s;
	c2 = (unsigned char)c;
	i = 0;
	while(i < n)
	{
		if(s2[i] == c2)
			return (s2 + i);
		i++;
	}
	return (0);
}
