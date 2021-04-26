/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:33:54 by junseole          #+#    #+#             */
/*   Updated: 2021/04/26 20:23:58 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	free(*line); //첫 번째 포인터에 할당되어있던 메모리 해제
	*line = new_line;
	return (1);
}

int			read_buf(t_buf *buf, char **line)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = ft_strlen(*line);
	if (!(resize(i, buf, line)))
		return (-1);
	flag = 0;
	j = 0;
	while (buf->buf[j])
	{
		(*line)[i++] = buf->buf[j];
		if (buf->buf[j++] == '\n')
		{
			i--;
			flag = 1;
			break ;
		}
	}
	(*line)[i] = 0;
	i = 0;
	while (buf->buf[j]) //다음 While문을 통해 Size를 측정하여 안에 크기가 0보다 작은지 큰지 유무를 판단하는 과정 작을 경우 erase_buf를 활용하여 head를 삭제한다.
		buf->buf[i++] = buf->buf[j++];
	buf->buf[i] = 0;
	return (flag);
}

int			get_next_line(int fd, char **line)
{
	static t_buf	*head;
	t_buf			*buf;
	int				size;
	int				find;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > 999 //테스트키 파일에 fd가 999까지의 조건이 있어 걸어준 조건
				|| (!head && !(head = new_buf(fd)))
				|| !(buf = find_buf(fd, head)))
		return (-1);
	*line = 0;
	if ((find = read_buf(buf, line)))
		return (find);
	while ((size = read(fd, buf->buf, BUFFER_SIZE)) > 0) // 크기를 읽으면서 크기가 0보다 클 경우 반환
	{
		buf->buf[size] = 0;
		if ((find = read_buf(buf, line)))
			return (find);
	}
	erase_buf(fd, &head);
	return (size);
}
