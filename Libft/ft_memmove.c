/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:23:51 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 02:23:52 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, int len)
{
	int				i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if(dst == src || len == 0)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	if (dst < src)
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	else
		while(i < len)
		{
			dst2[len -i -1] = src2[len -i -1];
			i++;
		}
	return (dst);
}
