/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:31:57 by namhkim           #+#    #+#             */
/*   Updated: 2021/05/16 23:03:07 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int							print_type(va_list cur_list, t_info *str_info)
{
	int			ret;

	ret = 0;
	if (str_info->type == 'c')
		ret = print_char(va_arg(cur_list, int), str_info);
	else if (str_info->type == '%')
		ret = print_char(str_info->type, str_info);
	else if (str_info->type == 's')
		ret = print_string(va_arg(cur_list, char *), str_info);
	else if (str_info->type == 'd' || str_info->type == 'i')
		ret = print_num(va_arg(cur_list, int), str_info, "0123456789");
	else if (str_info->type == 'u')
		ret = print_num(va_arg(cur_list, unsigned int), str_info, "0123456789");
	else if (str_info->type == 'x')
		ret = print_num(va_arg(cur_list, unsigned int), str_info, "0123456789abcdef");
	else if (str_info->type == 'X')
		ret = print_num(va_arg(cur_list, unsigned int), str_info, "0123456789ABCDEF");
	else if (str_info->type == 'p')
		ret = print_num(va_arg(cur_list, unsigned long long)
								, str_info, "0123456789abcdef");
	return (ret);
}

void						exception(va_list cur_list, char c, t_info *str_info)
{
	if (c == '0' && str_info -> width == 0 && str_info ->prec == -1)//초기화 상태에서 폭 옵션이 켜지는 경우
		str_info->zero = 1;
	else if(c == '-') //마이너스 나온 경우
		str_info->minus = 1;
	else if(c == '.')
		str_info->prec = 0;
	else if(ft_isdigit(c) || c == '*')
	{
		if(ft_isdigit(c))
			check_value_num(c, str_info);
		else
			check_value_wildcard(cur_list, str_info);
	}
}

int							parsing_sentance(char *str, va_list cur_list)
{
	int			ret;
	t_info		*str_info;

	ret = 0;
	if (!(str_info = malloc(sizeof(t_info))))
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			init_state(str_info);
			while (*(++str) && !(ft_strchr(AT_INFO, (char)*str)))
				exception(cur_list, (char)*str, str_info);
			str_info->type = *str++;
			if ((str_info->minus == 1 || str_info->prec > -1) && str_info->type != '%')//왼쪽정렬부터 시작하니 앞에 0을 넣을필요 X
				str_info->zero = 0;
			if (str_info->type == 'p' || str_info->type == 'x' || str_info->type == 'X')
				str_info->base = 16;
			ret += print_type(cur_list, str_info);
		}
		else
			ret += ft_putchar(*str++);
	}
	free(str_info);
	return (ret);
}

int							ft_printf(const char *str, ...)
{
	int			ret;
	va_list		cur_list;

	va_start(cur_list, str);
	ret = parsing_sentance((char *)str, cur_list);
	va_end(cur_list);
	return (ret);
}
