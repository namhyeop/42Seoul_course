/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:15:06 by junseole          #+#    #+#             */
/*   Updated: 2021/04/26 20:16:40 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct		s_buf
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_buf	*next;
}					t_buf;

size_t				size_check(const char *s);
size_t				ft_strlen(const char *s);
t_buf				*new_buf(int fd);
t_buf				*find_buf(int fd, t_buf *buf);
int					read_buf(t_buf *buf, char **line);
int					resize(size_t len, t_buf *buf, char **line);
void				erase_buf(int fd, t_buf **head);
int					get_next_line(int fd, char **line);

#endif
