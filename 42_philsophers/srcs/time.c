/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:35:22 by namhkim           #+#    #+#             */
/*   Updated: 2022/04/28 16:44:36 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_current_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	sleep_philo(t_table *table)
{
	long long	sleep_time;
	long long	current_time;
	long long	start_time;

	sleep_time = (long long)(table->time_to_sleep);
	start_time = get_current_time();
	while (!(table->die))
	{
		current_time = get_current_time();
		if ((current_time - start_time) >= sleep_time)
			break ;
		usleep(10);
	}
}

void	eat_philo(t_table *table)
{
	long long	eat_time;
	long long	current_time;
	long long	start_time;

	eat_time = (long long)(table->time_to_eat);
	start_time = get_current_time();
	while (!(table->die))
	{
		current_time = get_current_time();
		if ((current_time - start_time) >= eat_time)
			break ;
		usleep(10);
	}
}
