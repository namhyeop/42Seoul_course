/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakwak <jakwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:54:34 by jakwak            #+#    #+#             */
/*   Updated: 2020/12/13 05:54:36 by jakwak           ###   ########.fr       */
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
