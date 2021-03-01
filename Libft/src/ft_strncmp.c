/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:37:21 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 16:40:55 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	*tmpS1;
	unsigned char	*tmpS2;
	int		i;

	tmpS1 = (unsigned char *)s1;
	tmpS2 = (unsigned char *)s2;
	i = 0;

	while (i < n && tmpS1[i] && tmpS2[i])
	{
		if(tmpS1[i] != tmpS2[i])
			return (tmpS1[i] - tmpS2[i]);
		i++;
	}
	if(i == n)
		return (0);
	return (tmpS1[i] - tmpS2[i]);
}
