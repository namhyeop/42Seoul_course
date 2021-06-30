/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:52:05 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/30 16:53:07 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	clean(void)
{
	t_node *ptr;

	ptr = getinstnace();
	ptr->cnt = 0;
	ptr->pid.num = 0;
	ptr->len.num = 0;
	ptr->step = 0;
	if (ptr->str)
		free(ptr->str);
}
