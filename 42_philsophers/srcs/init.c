/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:36:00 by namhkim           #+#    #+#             */
/*   Updated: 2022/04/28 16:44:43 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_argument(t_table *table)
{
	if (table->number_of_philosopers < 1)
		return (error("The number of philosophers must be at least one.\n"));
	if (table->number_of_philosopers > 200
		|| table->time_to_die < 60
		|| table->time_to_eat < 60
		|| table->time_to_sleep < 60)
		return (error("Do not input under 60ms"));
	if (table->number_of_times_each_philosopher_must_eat == 0)
		return (error("Each philosopher must eat at least once.\n"));
	return (TRUE);
}

int	init_fork(t_table *table)
{
	int	i;

	if (pthread_mutex_init(&(table->eating), NULL))
		return (error("Failed to initialize mutex.\n"));
	if (pthread_mutex_init(&(table->printing), NULL))
		return (error("Failed to initialize mutex.\n"));
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosopers);
	if (!table->fork)
		return (error("Failed to allocate memory.\n"));
	i = 0;
	while (i < table->number_of_philosopers)
	{
		if (pthread_mutex_init(&table->fork[i], NULL))
			return (error("Failed to initialize mutex.\n"));
		i++;
	}
	return (TRUE);
}

int	init_philo(t_table *table)
{
	int	i;

	table->philo = malloc(sizeof(t_philo) * table->number_of_philosopers);
	if (!table->philo)
		return (error("Failed to allocate memory.\n"));
	i = 0;
	while (i < table->number_of_philosopers)
	{
		table->philo[i].id = i;
		table->philo[i].left_fork = i;
		table->philo[i].right_fork = (i + 1) % table->number_of_philosopers;
		table->philo[i].last_eat_time = 0;
		table->philo[i].eat_count = 0;
		table->philo[i].table = table;
		i++;
	}
	return (TRUE);
}

int	table_input(t_table *table, int argc, char **argv)
{
	table->number_of_philosopers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		table->number_of_times_each_philosopher_must_eat = -1;
	table->die = 0;
	table->eat_check = 0;
	table->start_time = 0;
	if (check_argument(table) == FALSE)
		return (FALSE);
	if (init_fork(table) == FALSE)
		return (FALSE);
	if (init_philo(table) == FALSE)
		return (FALSE);
	return (TRUE);
}
