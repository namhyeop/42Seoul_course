/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:15:18 by junseole          #+#    #+#             */
/*   Updated: 2021/04/26 20:16:42 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		size_check(const char *s)
{
	size_t ret;

	if (!s || *s == '\n')
		return (0);
	ret = 0;
	while (*s && *s != '\n')
	{
		ret++;
		s++;
	}
	return (ret);
}

size_t		ft_strlen(const char *s)
{
	size_t ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

t_buf		*new_buf(int fd)
{
	t_buf *ret;

	if (!(ret = malloc(sizeof(t_buf))))
		return (0);
	ret->fd = fd;
	ret->buf[0] = 0;
	ret->next = 0;
	return (ret);
}

t_buf		*find_buf(int fd, t_buf *buf)
{
	if (buf->fd == fd)
		return (buf);
	if (!buf->next)
		return (buf->next = new_buf(fd));
	return (find_buf(fd, buf->next));
}

void		erase_buf(int fd, t_buf **head)
{
	t_buf *pre;
	t_buf *cur;

	pre = *head;
	if (pre->fd == fd)
	{
		cur = pre->next;
		free(pre);
		*head = cur;
		return ;
	}
	while (pre->next->fd != fd)
		pre = pre->next;
	cur = find_buf(fd, *head);
	pre->next = cur->next;
	free(cur);
}
