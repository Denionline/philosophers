/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:57:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 19:59:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	manage_forks(t_philo *philo, enum e_mutex_action action)
{
	if (action == UNLOCK)
	{
		mutex_handle(philo->fork.left, UNLOCK);
		mutex_handle(philo->fork.right, UNLOCK);
		return (1);
	}
	if (is_simulation_finished(philo->head))
		return (0);
	if (philo->id % 2)
	{
		mutex_handle(philo->fork.right, LOCK);
		if (is_simulation_finished(philo->head))
			return (mutex_handle(philo->fork.right, UNLOCK), 0);
		print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
		mutex_handle(philo->fork.left, LOCK);
		if (is_simulation_finished(philo->head))
			return (mutex_handle(philo->fork.left, UNLOCK), mutex_handle(philo->fork.right, UNLOCK), 0);
		print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
	}
	else
	{
		mutex_handle(philo->fork.left, LOCK);
		if (is_simulation_finished(philo->head))
			return (mutex_handle(philo->fork.left, UNLOCK), 0);
		print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
		mutex_handle(philo->fork.right, LOCK);
		if (is_simulation_finished(philo->head))
			return (mutex_handle(philo->fork.right, UNLOCK), mutex_handle(philo->fork.left, UNLOCK), 0);
		print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
	}
	return (1);
}

static void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)(args);
	precise_sleep(!(philo->id % 2) * 1e1);
	while (!is_simulation_finished(philo->head))
	{
		if (!manage_forks(philo, LOCK))
			break ;
		actions(philo, EAT);
		manage_forks(philo, UNLOCK);
		actions(philo, SLEEP);
		actions(philo, THINK);
		precise_sleep((philo->head->n_philos % 2 && philo->id % 2) * 1e1);
	}
	if (philo->is_dead)
		actions(philo, DIE);
	return (NULL);
}

int	simulation(t_head *head, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < head->n_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]))
			perror("Erro thread");
		i++;
	}
	i = 0;
	while (i < head->n_philos)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
