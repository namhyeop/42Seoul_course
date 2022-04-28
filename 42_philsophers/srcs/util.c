/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:35:11 by namhkim           #+#    #+#             */
/*   Updated: 2022/04/28 16:44:34 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (nptr[i])
	{
		if (ft_isdigit(nptr[i]) == FALSE)
			return (-1);
		result = 10 * result + (nptr[i] - '0');
		i++;
	}
	return (result);
}

int	check_argument_int(char *s)
{
	int		arg;

	arg = ft_atoi(s);
	if (arg < 0 || arg > 2147483647)
		return (FALSE);
	return (TRUE);
}

void	print_action(t_table *table, int philo_id, char *str)
{
	pthread_mutex_lock(&(table->printing));
	if (!(table->die))
	{
		printf("%lli ", get_current_time() - table->start_time);
		printf("%i ", philo_id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(table->printing));
	return ;
}

void	check_all_philo_eat(t_table *table, t_philo *philo)
{
	int		i;

	i = 0;
	while ((table->number_of_times_each_philosopher_must_eat != -1)
		&& (i < table->number_of_philosopers)
		&& (philo[i].eat_count
			> table->number_of_times_each_philosopher_must_eat))
	{
		i++;
	}
	if (i == table->number_of_philosopers)
		table->eat_check = 1;
}
