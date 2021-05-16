/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:12:08 by namhkim           #+#    #+#             */
/*   Updated: 2021/05/16 23:01:27 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		check_width_str(char **str2, t_info *str_info)
{
	char	*width;
	size_t	i;

	i = 0;
	if (ft_strlen(*str2) >= (size_t)str_info->width)
		return ((int)ft_strlen(*str2));
	if (!(width = malloc(sizeof(char) * (str_info->width - ft_strlen(*str2)) + 1)))
		return (0);
	while (i < (size_t)str_info->width - ft_strlen(*str2))
	{
		if (str_info->zero == 1) //?
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (str_info->minus == 1)
		*str2 = ft_strjoin(*str2, width, 3);
	else
		*str2 = ft_strjoin(width, *str2, 3);
	return (str_info->width);
}

char	*read_str(char *str, int prec)
{
	size_t	str_len;
	char	*str2;
	int		i;

	i = 0;
	str_len = ft_strlen(str);
	if((size_t)prec >= str_len)
		prec = (int)str_len;
	if(!(str2 = malloc(sizeof(char) * prec + 1)))
		return (0);
	while (i < prec)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

int		print_string(char *str, t_info *str_info)
{
	int		ret;
	char	*str2;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (str_info->prec == -1 || str_info->prec > (int)ft_strlen(str))
		str_info->prec = (int)ft_strlen(str);
	str2 = read_str(str, str_info->prec);
	ret = check_width_str(&str2, str_info);
	ft_putstr(str2);
	free(str2);
	return (ret);
}
