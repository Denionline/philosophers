/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:28:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:14 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_there_some_error(t_head *head)
{
	if (head->n_philos > 200)
		return (handle_errors(ERR_N_PHILO_MORE_THAN_LIMIT));
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
	(*head)->philos_pid = calloc((*head)->philos_pid, sizeof(int));
	(*head)->forks = sem_open("/sem_forks", O_CREAT, 677, (*head)->n_philos);
	(*head)->print = sem_open("/sem_print", O_CREAT, 677, 1);
	(*head)->dead = sem_open("/sem_dead", O_CREAT, 677, 0);
	(*head)->start_time = get_time_now(MILISECONDS);
	return (is_there_some_error(*head));
}
