/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:26:52 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 02:26:52 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*curr;
	t_list	*temp;

	if (lst == 0 || f == 0)
		return (0);
	if ((new_head = ft_lstnew(f(lst->content))) == 0)
		return (0);
	curr = new_head;
	lst = lst->next;
	while (lst)
	{
		if ((temp = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		curr->next = temp;
		curr = temp;
		lst = lst->next;
	}
	return (new_head);
}
