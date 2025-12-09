/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:26:11 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 17:41:11 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <semaphore.h>
# include <fcntl.h>

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
	SOMEONE_DIED,
};

typedef struct s_head	t_head;

typedef struct s_philo
{
	int			id;
	long		meals;
	time_t		last_meal;
	t_head		*head;
}	t_philo;

typedef struct s_head
{
	time_t		n_philos;
	time_t		meals_limit;
	time_t		start_time;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*dead;
	struct s_time_to
	{
		time_t	die;
		time_t	eat;
		time_t	sleep;
	}			time_to;
	int			*philos_pid;
	t_philo		*philos;
}	t_head;

int			parse(t_head **head, char *args[], int len);
int			simulation(t_head *head);
void		print_actions(t_head *head, int idx, time_t time, int action);
int			get_number_as_string(long n, char *buff);
long		get_string_as_number(char *n);

void		precise_sleep(long milisec);
int			handle_errors(enum e_errors code);

// aux/actions.c
void		actions(t_philo *philo, enum e_actions action);

// get/
time_t		get_time_now(enum e_seconds type);

int			end(t_head *head, int code, char *description);

#endif
