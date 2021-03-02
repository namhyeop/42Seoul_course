/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:06:02 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/02 00:06:02 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	int		i;
	char	*result;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0 || s2 == 0)
		return (s1 == 0 ? ft_strdup(2) : ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((result = (char *)malloc(sizeof(char) * len)) == 0)
		return (0);
	i = ft_strlcpy(result, s1, len);
	ft_strlcat(result + i, s2, len);
	return (result);
}
