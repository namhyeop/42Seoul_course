/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:59:29 by namhkim           #+#    #+#             */
/*   Updated: 2021/05/16 21:56:05 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int			print_width(t_info *str_info)
{
	int ret;

	ret = 1;
	while (ret < str_info->width)
	{
		if (str_info->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
			ret++;
	}
	return (ret - 1);
}

int			print_char(int c, t_info *str_info)
{
	int		ret;

	ret = 0;
	if (str_info->type == '%' && str_info->minus == 1) //minus 옵션인데 숫자가 올경우 뒤에 0을 붙쳐주면 다른 숫자가 되므로 옵션을 꺼줘야 한다.
		str_info->zero = 0;
	if (str_info->minus == 1)
		ret += ft_putchar(c);
	ret += print_width(str_info);
	if(str_info->minus == 0)
	ret += ft_putchar(c);
	return (ret);
}
