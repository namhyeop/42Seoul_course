/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakwak <jakwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:52:47 by jakwak            #+#    #+#             */
/*   Updated: 2020/12/13 05:52:48 by jakwak           ###   ########.fr       */
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
