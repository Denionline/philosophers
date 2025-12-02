/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:28:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/02 20:46:09 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*get_forks(t_head *head)
{
	t_fork	*forks;
	int		i;

	forks = calloc(head->n_philos + 1, sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = -1;
	while (++i < head->n_philos)
	{
		pthread_mutex_init(&forks[i].mutex, NULL);
		forks[i].exists = TRUE;
		forks[i].id = i;
	}
	return (forks);
}

t_philo	*get_philos(t_head *head)
{
	t_philo	*philos;
	int		i;

	philos = calloc(head->n_philos + 1, sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < head->n_philos)
	{
		philos[i].id = (i + 1);
		philos[i].head = head;
		philos[i].exists = TRUE;
		philos[i].left_fork = &head->forks[i];
		philos[i].right_fork = &head->forks[(i + 1) % head->n_philos];
	}
	return (philos);
}

int	parse(t_head **head, char *args[], int len)
{
	int	i;

	if (len < 4 || len > 5)
		return (1);
	(*head) = calloc(1, sizeof(t_head));
	if (!(*head))
		return (1);
	(*head)->n_philos = ft_atol(args[0]);
	(*head)->time_to.die = ft_atol(args[1]);
	(*head)->time_to.eat = ft_atol(args[2]);
	(*head)->time_to.sleep = ft_atol(args[3]);
	(*head)->meals_limit = -1;
	if (len == 5)
		(*head)->meals_limit = ft_atol(args[4]);
	(*head)->philos = get_philos(*head);
	(*head)->forks = get_forks(*head);
	return (0);
}
