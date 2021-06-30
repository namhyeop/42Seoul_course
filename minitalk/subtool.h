/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:53:20 by namhkim           #+#    #+#             */
/*   Updated: 2021/06/30 14:45:15 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBTOOL_H
# define SUBTOOL_H

# include <signal.h>
# include <unistd.h>

void		ft_putnbr_fd(int n, int fd);
void		write_nbr(int n, int fd);
#endif
