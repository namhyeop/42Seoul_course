/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:00:37 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 02:27:26 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, int len)
{
	int	tmp_len;
	int	i;

	if (!src)
		return (0);
	tmp_len = ft_strlen(src);
	if (dst == 0 || len == 0)
		return (tmp_len);
	i = 0;
	while (i < tmp_len && i + 1 < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (tmp_len);
}
