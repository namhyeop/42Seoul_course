/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:25:51 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 02:27:09 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;
	char	c2;

	s2 = (char) *s;
	c2 = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s2[i] == c2)
			return(s2 + i);
		i--;
	}
	if (s2[i] == c2)
		return (s2);
	return (0);
}
