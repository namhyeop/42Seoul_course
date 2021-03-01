/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:22 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 17:31:32 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int	len;
	int	i;
	char	*result;

	len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while(i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[len] = 0;
	return (result);
}
