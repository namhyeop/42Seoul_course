/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:52:00 by namhkim           #+#    #+#             */
/*   Updated: 2021/05/16 23:02:28 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define AT_INFO "cspdiuxX%"

/*
	*** 왼쪽정렬, 출력남는공간 0확보, 폭, 지정숫자만큼 폭 지정, 정밀도,
	*** 지정 숫자만큼 소수점 아래 출력, 서식문자로 출력할 인수 앞에 가변인수로 필드의 폭 결정  ***
*/
typedef struct
{
	int		minus; //왼쪽정렬
	int		zero; // 0확보
	int		width; // 폭 지정
	char	type; // 서식지정자
	int		prec; // 정밀도
	int		base; // 진수
	int		sign; //음수 양수
}			t_info;

/*
	ft_printf_main.c
*/
int							ft_printf(const char *str, ...);
int							parsing_sentance(char *str, va_list cur_list);
void						exception(va_list cur_list, char c, t_info *str_info);
int							print_type(va_list cur_list, t_info *str_info);
//void						check_width_prec(va_list cur_list, char c, t_info *str_info);

/*
	ft_printf_int.c
*/
int							print_num(unsigned long long nbr, t_info *str_info, char *base);
void						read_nbr(char **str, t_info *str_info, int base_len);
void						check_nbr_width(char **str, t_info *str_info);
void						add_minus(char **str, t_info *str_info, int base_len);
int							add_prefix(char **str);

/*
	ft_printf_char.c
*/
int							print_char(int c, t_info *str_info);
int							print_width(t_info *str_info);

/*
	ft_printf_sub.c
*/

char						*ft_ulltoa(unsigned long long nbr, char *base, t_info *str_info, int base_len);
int							ft_nbrlen(unsigned long long nbr, t_info *str_info);
void						check_value_wildcard(va_list cur_list, t_info *str_info);
void						check_value_num(char c, t_info *str_info);
void						init_state(t_info *info);

/*
	ft_printf_sub.c
*/
int							print_string(char *str, t_info *str_info);
char						*read_str(char *str, int prec);
int							check_width_str(char **str2, t_info *str_info);

#endif
