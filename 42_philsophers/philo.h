/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:34:20 by namhkim           #+#    #+#             */
/*   Updated: 2022/04/28 16:44:30 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		last_eat_time;
	int				eat_count;
	struct s_table	*table;
	pthread_t		thread_id;
}					t_philo;

typedef struct s_table
{
	int					number_of_philosopers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					die;
	int					eat_check;
	long long			start_time;
	pthread_mutex_t		*fork;
	pthread_mutex_t		eating;
	pthread_mutex_t		printing;
	t_philo				*philo;
}				t_table;

int			parse(int argc, char **argv);
int			check_argument_int(char *s);
int			ft_atoi(const char *nptr);
int			check_digit(char *s);
int			error(char *msg);
void		sleep_philo(t_table *table);
void		eat_philo(t_table *table);
int			start_dining(t_table *table, t_philo *philo);
int			table_input(t_table *table, int argc, char **argv);
void		print_action(t_table *table, int philo_id, char *str);
void		check_all_philo_eat(t_table *table, t_philo *philo);

long long	get_current_time(void);

#endif