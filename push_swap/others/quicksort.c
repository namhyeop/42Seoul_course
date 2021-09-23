/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:05:56 by namhkim           #+#    #+#             */
/*   Updated: 2021/09/23 21:20:23 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	skip_order(t_stack *s, int order, int i)
{
	int	len;

	len = dlst_len(s->head) - order;
	if (len < 0)
		len = -len;
	if (order >= len)
	{
		while (len--)
		{
			if (i == 0)
				reverse_rotate(s, "rra");
			else
				reverse_rotate(s, "rrb");
		}
	}
	else
	{
		while (order--)
		{
			if (i == 0)
				rotate(s, "ra");
			else
				rotate(s, "rb");
		}
	}
}

void	swap_both(t_stacks *s)
{
	if (s->stack_b->head && s->stack_b->head->next
		&& s->stack_a->head->pos > s->stack_a->head->next->pos
		&& s->stack_b->head->pos < s->stack_b->head->next->pos)
	{
		swap(s->stack_a, NULL);
		swap(s->stack_b, "ss");
	}
}

void	quicksort(t_stacks *stacks, int len)
{
	int	order;
	int	sorted;

	sorted = 1;
	while (is_sorted(stacks->stack_a->head) != true)
	{	
		order = -1;
		while (order < len && stacks->stack_a->head != NULL)
		{
			move_a_to_b(stacks, len, order);
			len = dlst_len(stacks->stack_a->head);
			order = is_in_order(stacks->stack_a->tail, 1);
		}
		quicksort2(stacks, len, order);
	}
}

void	quicksort2(t_stacks *stacks, int len, int order)
{
	if (stacks->stack_b->head != NULL)
	{
		move_b_to_a(stacks, len, order);
		len = dlst_len(stacks->stack_b->head);
		order = is_in_order(stacks->stack_b->tail, -1);
		if (len == order)
		{
			while (stacks->stack_b->head)
				push(stacks->stack_b, stacks->stack_a, "pa");
		}
		if (stacks->stack_b->head && dlst_len(stacks->stack_b->head) < 20)
			selectionsort_b(stacks, len);
	}
}
