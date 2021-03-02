/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:22:43 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 02:22:43 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_word_cnt(char const *s, char c)
{
	int cnt;
	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		s++;
	}
	return (cnt);
}

static void	*ft_free(char **ret)
{
	int i;
	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
	ret = 0;
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char		**ret;
	int			index;
	char const	*tmp;
	if (!s || !(ret = (char **)malloc(sizeof(char *) * get_word_cnt(s, c) + 1)))
		return (0);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			tmp = s;
			while (*s && *s != c)
				s++;
			if (!(ret[index] = (char *)malloc(s - tmp + 1)))
				return (ft_free(ret));
			ft_strlcpy(ret[index], tmp, s - tmp + 1);
			index++;
		}
		else if (*s != '\0')
			s++;
	}
	ret[index] = 0;
	return (ret);
}
