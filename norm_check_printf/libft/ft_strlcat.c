/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:01:57 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 18:01:58 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (*dst != 0 && len < dstsize)
	{
		len++;
		dst++;
	}
	while (*src != 0 && len + 1 < dstsize)
	{
		*dst++ = *src++;
		len++;
	}
	if (len < dstsize)
		*dst = 0;
	while (*src++ != 0)
		len++;
	return (len);
}
