/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:08:38 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/01 00:19:24 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, int n)
{
	int	i;
	unsigned char	*addr;

	addr = (unsigned char *)s;
	i = 0;
	while(i < n)
		addr[i++] = 0;
}
