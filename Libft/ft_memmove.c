/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:01:01 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 18:01:02 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst == src || len == 0)
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
		while (i < len)
		{
			dst2[len - i - 1] = src2[len - i - 1];
			i++;
		}
	return (dst);
}
