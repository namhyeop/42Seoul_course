/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:52:00 by namhkim           #+#    #+#             */
/*   Updated: 2021/05/17 14:14:38 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define AT_INFO "cspdiuxX%"

typedef struct
{
	int		minus;
	int		zero;
	int		width;
	char	type;
	int		prec;
	int		base;
	int		sign;
}			t_info;

int			ft_printf(const char *str, ...);
int			parsing_sentance(char *str, va_list cur_list);
void		parsing_2(char *str, va_list cur_lsist, t_info *str_info);
void		exception(va_list cur_list, char c, t_info *str_info);
int			print_type(va_list cur_list, t_info *str_info);

int			print_num(unsigned long long nbr, t_info *str_info, char *base);
void		read_nbr(char **str, t_info *str_info, int base_len);
void		check_nbr_width(char **str, t_info *str_info);
void		add_minus(char **str, t_info *str_info, int base_len);
int			add_prefix(char **str);

int			print_char(int c, t_info *str_info);
int			print_width(t_info *str_info);

char		*ft_ulltoa(unsigned long long nbr, char *base,
						t_info *str_info, int base_len);
int			ft_nbrlen(unsigned long long nbr, t_info *str_info);
void		check_value_wildcard(va_list cur_list, t_info *str_info);
void		check_value_num(char c, t_info *str_info);
void		init_state(t_info *info);

int			print_string(char *str, t_info *str_info);
char		*read_str(char *str, int prec);
int			check_width_str(char **str2, t_info *str_info);

#endif
