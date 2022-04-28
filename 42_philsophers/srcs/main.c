/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:35:51 by namhkim           #+#    #+#             */
/*   Updated: 2022/04/28 16:44:42 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (parse(argc, argv) == FALSE)
		return (FALSE);
	if (table_input(&table, argc, argv) == FALSE)
		return (FALSE);
	if (start_dining(&table, (&table)->philo) == FALSE)
		return (FALSE);
	return (TRUE);
}
