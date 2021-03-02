/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:45:25 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/02 18:45:25 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
		new->content = content;
		new->next = 0;
		return (new);
}
