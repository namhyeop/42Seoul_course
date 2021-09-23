/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:05:56 by namhkim           #+#    #+#             */
/*   Updated: 2021/09/23 21:20:26 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_dlist *lst)
{
	int	median;
	int	len;

	median = 0;
	len = 0;
	while (lst)
	{
		median += lst->pos;
		len++;
		lst = lst->next;
	}
	median /= len;
	return (median);
}

void	move_a_to_b(t_stacks *s, int len, int order)
{
	int	pivot;

	pivot = find_median(s->stack_a->head);
	len = dlst_len(s->stack_a->head);
	order = is_in_order(s->stack_a->tail, 1);
	if (order != 1)
		len = len - order;
	while (len--)
	{
		if (s->stack_a->head->pos >= pivot
			&& s->stack_a->head->next->pos >= pivot)
			rotate(s->stack_a, "ra");
		else
		{
			swap_both(s);
			if (s->stack_a->head->pos > s->stack_a->head->next->pos)
				swap(s->stack_a, "sa");
			push(s->stack_a, s->stack_b, "pb");
		}
	}
	skip_order(s->stack_a, order, 0);
}

void	move_b_to_a(t_stacks *s, int len, int order)
{
	int	pivot;

	pivot = find_median(s->stack_b->head);
	len = dlst_len(s->stack_b->head);
	order = is_in_order(s->stack_b->tail, -1);
	if (order != 1)
		len = len - order;
	while (len--)
	{
		if (s->stack_b->head->pos <= pivot)
		{
			if (dlst_len(s->stack_b->head) == 1)
				push(s->stack_b, s->stack_a, "pa");
			else
				rotate(s->stack_b, "rb");
		}
		else
		{
			swap_both(s);
			if (s->stack_b->head->pos < s->stack_b->head->next->pos)
				swap(s->stack_b, "sb");
			push(s->stack_b, s->stack_a, "pa");
		}
	}
	skip_order(s->stack_b, order, 1);
}
