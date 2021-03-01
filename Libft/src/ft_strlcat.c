/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:07:57 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 01:24:44 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	len;

	len = 0;
	while(*dst != 0 && len < dstsize)
	{
		len++;
		dst++;
	}
	while(*src != 0 && len + 1 < dstsize)
	{
		*dst++ = *src++;
		len++;
	}
	if(len < dstsize)
		*dst = 0;
	while(*src++ != 0)
		len++;
	return (len);
}
