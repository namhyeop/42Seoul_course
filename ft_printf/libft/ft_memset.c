/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:01:06 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 18:01:07 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*addr;
	unsigned char	temp;

	i = 0;
	addr = (unsigned char *)b;
	temp = (unsigned char)c;
	while (i < len)
	{
		addr[i] = temp;
		i++;
	}
	return (b);
}
