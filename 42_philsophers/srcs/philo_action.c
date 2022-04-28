/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:35:34 by namhkim           #+#    #+#             */
/*   Updated: 2022/04/28 16:44:38 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&(table->fork[philo->left_fork]));
	print_action(table, philo->id, "has taken a fork.");
	pthread_mutex_lock(&(table->fork[philo->right_fork]));
	print_action(table, philo->id, "has taken a fork.");
	pthread_mutex_lock(&(table->eating));
	print_action(table, philo->id, "is eating.");
	pthread_mutex_unlock(&(table->eating));
	eat_philo(table);
	philo->last_eat_time = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&(table->fork[philo->left_fork]));
	pthread_mutex_unlock(&(table->fork[philo->right_fork]));
}

void	*dining(void *void_philo)
{
	t_table		*table;
	t_philo		*philo;

	philo = (t_philo *)(void_philo);
	table = philo->table;
	if (philo->id % 2 == 1)
		usleep(10000);
	while (!(table->die))
	{
		eat(table, philo);
		if (table->eat_check)
			break ;
		print_action(table, philo->id, "is sleeping.");
		sleep_philo(table);
		print_action(table, philo->id, "is thinking.");
	}
	return (NULL);
}

void	is_philo_dead(t_table *table, t_philo *philo)
{
	int		i;

	while (table->eat_check != 1)
	{
		i = 0;
		while ((i < table->number_of_philosopers) && (table->die != 1))
		{
			pthread_mutex_lock(&(table->eating));
			if ((get_current_time() - philo[i].last_eat_time)
				> table->time_to_die)
			{
				print_action(table, i, "died.");
				table->die = 1;
			}
			pthread_mutex_unlock(&(table->eating));
			usleep(100);
			i++;
		}
		if (table->die == 1)
			break ;
		check_all_philo_eat(table, philo);
	}
}

void	stop_dining(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosopers)
	{
		pthread_mutex_unlock(&(table->fork[i]));
		pthread_mutex_destroy(&(table->fork[i++]));
	}
	i = 0;
	while (i < table->number_of_philosopers)
		pthread_join(philo[i++].thread_id, NULL);
	pthread_mutex_destroy(&(table->printing));
	pthread_mutex_destroy(&(table->eating));
	free(philo);
	free(table->fork);
}

int	start_dining(t_table *table, t_philo *philo)
{
	int		i;

	i = 0;
	table->start_time = get_current_time();
	while (i < table->number_of_philosopers)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, dining, &(philo[i])))
			return (error("Failed to create thread.\n"));
		philo[i].last_eat_time = get_current_time();
		i++;
	}
	is_philo_dead(table, philo);
	stop_dining(table, philo);
	return (TRUE);
}
