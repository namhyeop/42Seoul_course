/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:14:40 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 00:19:13 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft,h"

void	*ft_memccpy(void *dst, void *src, int c, int len)
{
	int	i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	c2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	c2 = (unsigned char)c;
	i = 0;

	while(i < n)
	{
		dst2[i] = src2[i];
		if(dst2[i] == c2)
			return (dst2 + i + 1);
		i++;
	}
	return (0);
}
