/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:26:11 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/04 11:49:44 by dximenes         ###   ########.fr       */
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

typedef struct s_time
{
	long long	die;
	long long	eat;
	long long	sleep;
}	t_time;

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
	long		last_meal;

	t_fork		*left_fork;
	t_fork		*right_fork;

	t_head		*head;
}	t_philo;

typedef struct s_head
{
	long			n_philos;
	long			meals_limit;
	t_time			time_to;

	enum e_bool		someone_died;
	mutex_t			mutex;
	mutex_t			print;

	t_fork			*forks;
	t_philo			*philos;
}	t_head;

int		parse(t_head **head, char *args[], int len);
int		philosophers(t_philo *philos);
int		print_actions(mutex_t *mutex, long time, int idx, enum e_actions action);
long	ft_atol(const char *n);

// aux/actions.c
int		action_eat(t_philo *philo);
int		action_die(t_philo *philo);
int		action_sleep(t_philo *philo);
int		action_think(t_philo *philo);

// get/
time_t	get_time(void);

#endif
