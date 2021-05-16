/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:37:51 by namhkim           #+#    #+#             */
/*   Updated: 2021/05/16 22:26:32 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int			add_prefix(char **str)
{
	*str = ft_strjoin("0x", *str, 2);
	return (ft_strlen(*str));
}

void		add_minus(char **str, t_info *str_info, int base_len)
{
	if (str_info->sign == 1 && str_info->zero == 1)
	{
		if (base_len >= str_info->width)
			*str = ft_strjoin("-", *str, 2);
		else
			*str[0] = '-';
	}
}

void		check_nbr_width(char **str, t_info *str_info)
{
	char	*width;
	size_t	i;

	if (ft_strlen(*str) >= (size_t)str_info->width) //문자열 길이가 더 크면 너비는 의미없다
		return ;
	if (!(width = malloc(sizeof(char) * (str_info->width - ft_strlen(*str)) + 1))) //width을 붙쳐주기 위한 과정
		return ;
	i = 0;
	while (i < (size_t)str_info->width - ft_strlen(*str))
	{
		if(str_info->zero == 1) //zero 옵션이 켜진 경우
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (str_info->minus == 1)
		*str = ft_strjoin(*str, width, 1);
	else
		*str = ft_strjoin(width, *str, 2);
}

void		read_nbr(char **str, t_info *str_info, int base_len)
{
	int		i;
	char	*prec;

	i = 0;
	if(str_info->prec > base_len)
	{
		if(!(prec = malloc(sizeof(char) * (str_info->prec - base_len) + 1)))
			return ;
		while (base_len + i < str_info->prec)
		{
			prec[i] = '0';
			i++;
		}
		prec[i] = '\0';
		*str = ft_strjoin(prec, *str, 3);
	}
	if(str_info->sign == 1 && str_info->zero == 0)
		*str = ft_strjoin("-", *str, 2);
}

int			print_num(unsigned long long nbr, t_info *str_info, char *base)
{
	char	*str;
	int		ret;
	int		base_len;

	ret = 0;
	if((str_info->type == 'd' || str_info->type == 'i') && (int)nbr < 0)
	{
		str_info->sign = 1;
		nbr *= -1;
	}
	base_len = ft_nbrlen(nbr, str_info);
	str = ft_ulltoa(nbr, base, str_info, base_len);
	read_nbr(&str, str_info, base_len);
	if (str_info->type == 'p')
		base_len = add_prefix(&str);
	check_nbr_width(&str, str_info);
	add_minus(&str, str_info, base_len);
	ret = (int)ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}
