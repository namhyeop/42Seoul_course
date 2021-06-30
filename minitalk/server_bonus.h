/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:11:28 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/30 16:14:34 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <stdlib.h>
# include "subtool.h"

union				u_data
{
	char			arr[4];
	int				num;
};

typedef struct		s_node
{
	int				cnt;
	int				step;
	union u_data	len;
	union u_data	pid;
	char			*str;
}					t_node;

void				clean(void);
t_node				*getinstance(void);
void				fnstep0(int num, struct __siginfo *ppp, void *pp);
void				fnstep1(int num, struct __siginfo *ppp, void *pp);
void				fnstep2(int num, struct __siginfo *ppp, void *pp);
#endif
