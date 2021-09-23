/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:33:17 by namhkim           #+#    #+#             */
/*   Updated: 2021/09/23 21:33:32 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_stack
{
	struct s_dlist	*head;
	struct s_dlist	*tail;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_stacks;

int			assign_pos(int len, int i, t_dlist *lst);
void		create_dlist(t_stack *stack_a, char **argv);
int			is_sorted(t_dlist *lst);
int			is_in_order(t_dlist *lst, int i);
int			main(int argc, char **argv);

void		error(void);
void		dlst_clear(t_stack *stack_a);
void		check_duplicate(char **argv, int i);
t_stacks	*initialise_stacks(void);
void		clear_stacks(t_stacks *stacks);

void		swap(t_stack *stack, char *str);
void		rotate(t_stack *stack, char *str);
void		reverse_rotate(t_stack *stack, char *str);
void		push(t_stack *src, t_stack *dest, char *str);
void		push1(t_stack *src, t_stack *dest);

int			power(int n, int ex);
void		sort_radix(t_stack *a, t_stack *b, int len);

int			smallest_num(t_stack *stack);
int			biggest_num(t_stack *stack);
void		direction(t_stack *stack, int len, int small);
void		selectionsort(t_stacks *s, int len);

#endif
