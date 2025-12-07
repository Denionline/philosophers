/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:28:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 22:42:45 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*get_forks(t_head *head)
{
	t_mutex	*forks;
	int		i;

	forks = calloc(head->n_philos, sizeof(t_mutex));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < head->n_philos)
		pthread_mutex_init(&forks[i++], NULL);
	return (forks);
}

t_philo	*get_philos(t_head *head)
{
	t_philo	*philos;
	int		i;

	philos = calloc(head->n_philos + 1, sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < head->n_philos)
	{
		philos[i].id = (i + 1);
		philos[i].head = head;
		philos[i].last_meal = head->start_time;
		if (head->forks)
			philos[i].fork.left = &head->forks[i];
		if (head->forks && head->n_philos > 1)
			philos[i].fork.right = &head->forks[(i + 1) % head->n_philos];
		i++;
	}
	return (philos);
}

int	is_there_some_error(t_head *head)
{
	if (head->n_philos > 200)
		return (handle_errors(ERR_N_PHILO_MORE_THAN_LIMIT));
	if (!head->philos || !head->forks)
		return (handle_errors(ERR_MALLOC));
	if (head->time_to.die < 0 || head->time_to.eat < 0)
		return (handle_errors(ERR_ARG_OUT_OF_LIMIT));
	if (head->time_to.sleep < 0 || head->meals_limit < 0)
		return (handle_errors(ERR_ARG_OUT_OF_LIMIT));
	return (FALSE);
}

int	parse(t_head **head, char *args[], int len)
{
	if (len < 4 || len > 5)
		return (handle_errors(ERR_INVALID_ARGS));
	(*head) = calloc(1, sizeof(t_head));
	if (!(*head))
		return (1);
	(*head)->n_philos = get_string_as_number(args[0]);
	(*head)->time_to.die = get_string_as_number(args[1]);
	(*head)->time_to.eat = get_string_as_number(args[2]);
	(*head)->time_to.sleep = get_string_as_number(args[3]);
	(*head)->meals_limit = LONG_MAX;
	if (len == 5)
		(*head)->meals_limit = get_string_as_number(args[4]);
	pthread_mutex_init(&(*head)->print, NULL);
	pthread_mutex_init(&(*head)->mutex, NULL);
	(*head)->start_time = get_time_now(MILISECONDS);
	(*head)->forks = get_forks(*head);
	(*head)->philos = get_philos(*head);
	return (is_there_some_error(*head));
}
