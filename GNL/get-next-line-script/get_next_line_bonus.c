/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:14:55 by junseole          #+#    #+#             */
/*   Updated: 2021/04/26 20:16:38 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			resize(size_t len, t_buf *buf, char **line)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	j = size_check(buf->buf);
	if (!(new_line = malloc(len + j + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	new_line[i] = 0;
	free(*line);
	*line = new_line;
	return (1);
}

int			read_buf(t_buf *buf, char **line)
{
	size_t	i;
	size_t	j;
	int		find;

	i = ft_strlen(*line);
	if (!(resize(i, buf, line)))
		return (-1);
	find = 0;
	j = 0;
	while (buf->buf[j])
	{
		(*line)[i++] = buf->buf[j];
		if (buf->buf[j++] == '\n')
		{
			i--;
			find = 1;
			break ;
		}
	}
	(*line)[i] = 0;
	i = 0;
	while (buf->buf[j])
		buf->buf[i++] = buf->buf[j++];
	buf->buf[i] = 0;
	return (find);
}

int			get_next_line(int fd, char **line)
{
	static t_buf	*head;
	t_buf			*buf;
	int				size;
	int				find;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > 999
				|| (!head && !(head = new_buf(fd)))
				|| !(buf = find_buf(fd, head)))
		return (-1);
	*line = 0;
	if ((find = read_buf(buf, line)))
		return (find);
	while ((size = read(fd, buf->buf, BUFFER_SIZE)) > 0)
	{
		buf->buf[size] = 0;
		if ((find = read_buf(buf, line)))
			return (find);
	}
	erase_buf(fd, &head);
	return (size);
}
