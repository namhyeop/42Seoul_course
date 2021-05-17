/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:55:33 by namhkim           #+#    #+#             */
/*   Updated: 2021/05/17 14:52:43 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void		init_state(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
	info->base = 10;
	info->sign = 0;
}

void		check_value_num(char c, t_info *str_info)
{
	if (str_info->prec == -1)
		str_info->width = str_info->width * 10 + c - '0';
	else
		str_info->prec = str_info->prec * 10 + c - '0';
}

void		check_value_wildcard(va_list cur_list, t_info *str_info)
{
	if (str_info->prec == -1)
	{
		str_info->width = va_arg(cur_list, int);
		if (str_info->width < 0)
		{
			str_info->minus = 1;
			str_info->width *= -1;
		}
	}
	else
		str_info->prec = va_arg(cur_list, int);
}

int			ft_nbrlen(unsigned long long nbr, t_info *str_info)
{
	int		cnt;

	if (nbr == 0 && str_info->prec != 0)
		return (1);
	cnt = 0;
	while (nbr)
	{
		nbr /= str_info->base;
		cnt++;
	}
	return (cnt);
}

char		*ft_ulltoa(unsigned long long nbr, char *base,
		t_info *str_info, int base_len)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * base_len + 1)))
		return (0);
	ret[base_len] = '\0';
	while (--base_len >= 0)
	{
		ret[base_len] = base[(nbr % str_info->base)];
		nbr /= str_info->base;
	}
	return (ret);
}
