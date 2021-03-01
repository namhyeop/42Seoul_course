/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:02:33 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 00:04:46 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *dst, int src, int len)
{
	int	i;
	unsigned char	*addr;
	unsigned char	tmp;

	i = 0;
	addr = (unsigned char *)b;
	tmp = (unsingned char)c;
	while(i < len)
		addr[i++] = tmp;
	
	return (b);
}
