/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:26:11 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 11:52:05 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef pthread_mutex_t mutex_t;

enum e_bool
{
	FALSE,
	TRUE,
};

enum e_actions
{
	FORK,
	EAT,
	DIE,
	SLEEP,
	THINK,
};

enum e_mutex_action
{
	LOCK,
	UNLOCK,
};

enum e_seconds
{
	SECONDS,
	MICROSECONDS,
	MILISECONDS,
};

typedef struct s_head t_head;

typedef struct s_info
{
	time_t	die;
	time_t	eat;
	time_t	sleep;
}	t_info;

typedef struct s_fork
{
	int		id;
	int		exists;
	mutex_t	mutex;
}	t_fork;


typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			meals;
	int			exists;
	time_t		last_meal;
	enum e_bool	is_dead;
	struct s_side
	{
		mutex_t	*left;
		mutex_t	*right;
	} fork;
	t_head		*head;
}	t_philo;

typedef struct s_head
{
	long		n_philos;
	long		meals_limit;
	t_info		time_to;
	enum e_bool	someone_died;
	enum e_bool	is_simulation_finished;
	mutex_t		mutex;
	mutex_t		to_check;
	mutex_t		print;
	time_t		start_time;
	t_fork		*forks;
	t_philo		*philos;
}	t_head;

int			parse(t_head **head, char *args[], int len);
int			simulation(t_head *head, t_philo *philos);
void		print_actions(t_head *head, int idx, time_t time, enum e_actions action);
long		ft_atol(const char *n);

enum e_bool	is_simulation_finished(t_head *head);
void		precise_sleep(long milisec);

// aux/actions.c
int			mutex_handle(mutex_t *mutex, enum e_mutex_action action);
void		actions(t_philo *philo, enum e_actions action);

// get/
time_t		get_time_now(enum e_seconds type);

void		end(t_head *head);

#endif
