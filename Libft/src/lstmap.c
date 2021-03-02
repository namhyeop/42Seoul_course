/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 05:54:05 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/03 06:05:52 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;

	if (!lst)
		return (NULL);
	head = malloc(sizeof(t_list));
	current = malloc(sizeof(t_list));
	if (!current || !head)
		return (NULL);
	head = f(lst);
	current = head;
	while (lst->next != NULL)
	{
		current->next = malloc(sizeof(t_list));
		if (!(current->next))
			return (NULL);
		current->next = f(lst->next);
		current->next->next = NULL;
		current = current->next;
		lst = lst->next;
	}
	return (head);
}
