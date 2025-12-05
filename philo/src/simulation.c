/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:57:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/05 16:33:02 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	manage_forks(t_philo *philo, enum e_mutex_action action)
{
	if (philo->head->is_simulation_finished)
		return ;
	if (philo->id % 2)
	{
		mutex_handle(philo->fork.right, action);
		if (action == LOCK)
			print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
		mutex_handle(philo->fork.left, action);
		if (action == LOCK)
			print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
	}
	else
	{
		mutex_handle(philo->fork.left, action);
		if (action == LOCK)
			print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
		mutex_handle(philo->fork.right, action);
		if (action == LOCK)
			print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
	}
}

static void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)(args);
	if (!(philo->id % 2))
		usleep(1000);
	while (!is_simulation_finished(philo->head))
	{
		actions(philo, THINK);
		manage_forks(philo, LOCK);
		actions(philo, EAT);
		manage_forks(philo, UNLOCK);
		actions(philo, SLEEP);
	}
	return (NULL);
}

int	simulation(t_head *head, t_philo *philos)
{
	int	i;

	head->start_time = get_time_now(MILISECONDS);
	i = 0;
	while (philos[i].exists)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]))
			perror("Erro thread");
		i++;
	}
	i = 0;
	while (philos[i].exists)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
