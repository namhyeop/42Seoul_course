/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:52:31 by namhkim           #+#    #+#             */
/*   Updated: 2021/03/02 19:52:31 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *curr;
	t_list *next;

	if (lst == 0 || del == 0)
		return ;
	curr = *lst;
	*lst = 0;
	while (curr)
	{
		next = curr->next; //curr -> next를  next에 담고
		ft_lstdelone(curr, del);//curr안에 들어있는 포인터의 주소를 활용하여 정보를 삭제한뒤
		curr = next;//curr을 반복문의 첫 번째 줄에서 실행한 curr -> next값으로 최신화 시킨다.
	}
}
