/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakwak <jakwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:52:55 by jakwak            #+#    #+#             */
/*   Updated: 2020/12/13 05:52:56 by jakwak           ###   ########.fr       */
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
