/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:30:50 by namhkim           #+#    #+#             */
/*   Updated: 2021/09/23 21:30:51 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_s;

	str_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str_s[i] == (unsigned char)c)
			return (str_s + i);
		i++;
	}
	return (NULL);
}
