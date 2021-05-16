/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:02:31 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 18:02:32 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s2;
	char	c2;

	s2 = (char *)s;
	c2 = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i--;
	}
	if (s2[i] == c2)
		return (s2);
	return (0);
}
