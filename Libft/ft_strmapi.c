/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:56:37 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/02 12:56:37 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*result;

	if (s == 0 || f == 0)
		return 0;
	len = ft_strlen(s);
	if ((result = (char *)malloc(sizeof(char)* (len + 1))) == 0)
		return 0;
	i = 0;
	while (s[i])
	{
		result[i] = f((unsigned int)i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
