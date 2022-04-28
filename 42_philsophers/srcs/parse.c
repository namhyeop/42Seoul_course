/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:35:40 by namhkim           #+#    #+#             */
/*   Updated: 2022/04/28 16:44:40 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	parse(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (error("[Error] wrong number of arguments.\n"));
	i = 1;
	while (i < argc)
	{
		if (check_argument_int(argv[i]) == FALSE)
			return (error("[Error] wrong argument type.\n"));
		i++;
	}
	return (TRUE);
}
