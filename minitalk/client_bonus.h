/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:49:06 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/30 15:52:14 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "subtool.h"
# include <signal.h>

union		u_data
{
	char	arr[4];
	pid_t	pid;
};

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
#endif
