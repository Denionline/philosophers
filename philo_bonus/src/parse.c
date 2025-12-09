/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:28:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 17:04:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*get_philos(t_head *head)
{
	t_philo	*philos;
	int		i;

	philos = calloc(head->n_philos, sizeof(t_philo));
	if (!philos)
		end(head, ERR_MALLOC, "philos");
	i = 0;
	while (i < head->n_philos)
	{
		philos[i].id = (i + 1);
		philos[i].head = head;
		philos[i].last_meal = head->start_time;
		i++;
	}
	return (philos);
}

static void	is_there_some_error(t_head *head)
{
	if (head->n_philos > 200)
		end(head, ERR_N_PHILO_MORE_THAN_LIMIT, NULL);
	if (!head->philos)
		end(head, ERR_MALLOC, NULL);
	if (head->time_to.die < 0 || head->time_to.eat < 0)
		end(head, ERR_ARG_OUT_OF_LIMIT, NULL);
	if (head->time_to.sleep < 0 || head->meals_limit < 0)
		end(head, ERR_ARG_OUT_OF_LIMIT, NULL);
}

int	parse(t_head **head, char *args[], int len)
{
	if (len < 4 || len > 5)
		end(head, ERR_INVALID_ARGS, NULL);
	(*head) = calloc(1, sizeof(t_head));
	if (!(*head))
		end(head, ERR_MALLOC, "head");
	(*head)->n_philos = get_string_as_number(args[0]);
	(*head)->time_to.die = get_string_as_number(args[1]);
	(*head)->time_to.eat = get_string_as_number(args[2]);
	(*head)->time_to.sleep = get_string_as_number(args[3]);
	(*head)->meals_limit = INT_MAX;
	if (len == 5)
		(*head)->meals_limit = get_string_as_number(args[4]);
	(*head)->philos_pid = calloc((*head)->philos_pid, sizeof(int));
	(*head)->forks = sem_open("/sem_forks", O_CREAT, 0644, (*head)->n_philos);
	(*head)->print = sem_open("/sem_print", O_CREAT, 0644, 1);
	(*head)->dead = sem_open("/sem_dead", O_CREAT, 0644, 0);
	(*head)->start_time = get_time_now(MILISECONDS);
	(*head)->philos = get_philos(head);
	is_there_some_error(head);
	return (0);
}
