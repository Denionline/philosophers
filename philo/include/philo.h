/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:26:11 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 22:44:29 by dximenes         ###   ########.fr       */
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
# include <limits.h>

typedef pthread_mutex_t	t_mutex;

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

enum e_errors
{
	ERR_MALLOC = 200,
	ERR_INVALID_ARGS,
	ERR_N_PHILO_MORE_THAN_LIMIT,
	ERR_ARG_OUT_OF_LIMIT,
};

typedef struct s_head	t_head;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	long		meals;
	time_t		last_meal;
	enum e_bool	is_dead;
	struct s_side
	{
		t_mutex	*left;
		t_mutex	*right;
	}			fork;
	t_head		*head;
}	t_philo;

typedef struct s_head
{
	time_t		n_philos;
	time_t		meals_limit;
	time_t		start_time;
	t_mutex		mutex;
	t_mutex		print;
	t_mutex		*forks;
	t_philo		*philos;
	struct s_time_to
	{
		time_t	die;
		time_t	eat;
		time_t	sleep;
	}			time_to;
}	t_head;

int			parse(t_head **head, char *args[], int len);
int			simulation(t_head *head, t_philo *philos);
void		print_actions(t_head *head, int idx, time_t time, int action);
int			get_number_as_string(long n, char *buff);
long		get_string_as_number(char *n);

enum e_bool	is_simulation_finished(t_head *head);
void		precise_sleep(long milisec);
int			handle_errors(enum e_errors code);

// aux/actions.c
int			mutex_handle(t_mutex *mutex, enum e_mutex_action action);
void		actions(t_philo *philo, enum e_actions action);

// get/
time_t		get_time_now(enum e_seconds type);

int			end(t_head *head);

#endif
