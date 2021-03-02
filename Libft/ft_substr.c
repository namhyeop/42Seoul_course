/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:00:17 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/02 00:00:17 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		s_len;
	char	*result;

	if(s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	s_len -= start;
	len = (len < s_len ? len : s_len) + 1;
	result = (char *)malloc(sizeof(char) * len);
	if (result == 0)
		return (0);
	ft_strlcpy(result, s+start, len);
	return (result);
}
