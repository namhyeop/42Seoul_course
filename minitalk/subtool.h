/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:43:41 by namhkim           #+#    #+#             */
/*   Updated: 2021/07/07 15:43:44 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBTOOL_H
# define SUBTOOL_H

# include <signal.h>
# include <unistd.h>
# include <limits.h>

void			writenbr(int n, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
#endif
