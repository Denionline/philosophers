/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:26:11 by dximenes          #+#    #+#             */
/*   Updated: 2025/11/24 23:37:21 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

enum e_bool
{
	FALSE,
	TRUE
};

typedef struct s_info
{
	long	number_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	limit_to_eat;
}	t_info;

typedef struct s_philo
{
	int			id;
	int			exists;
	t_info		info;
	pthread_t	thread;
}	t_philo;

typedef struct s_head
{
	t_philo	*philos;
}	t_head;

int	parse(t_head **head, char *args[], int len);
int	philosophers(t_philo *philos);
int	print(void);

// aux.c
long	ft_atol(const char *n);

#endif
