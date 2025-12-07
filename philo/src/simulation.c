/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:57:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 22:14:56 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	hold_forks(t_philo *philo, mutex_t *fork1, mutex_t *fork2)
{
	mutex_handle(fork1, LOCK);
	if (is_simulation_finished(philo->head))
		return (mutex_handle(fork1, UNLOCK), 0);
	print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
	mutex_handle(fork2, LOCK);
	if (is_simulation_finished(philo->head))
		return (mutex_handle(fork2, UNLOCK), mutex_handle(fork1, UNLOCK), 0);
	print_actions(philo->head, philo->id, get_time_now(MILISECONDS), FORK);
	return (1);
}

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
		if (!hold_forks(philo, philo->fork.right, philo->fork.left))
			return (0);
	}
	else
	{
		if (!hold_forks(philo, philo->fork.left, philo->fork.right))
			return (0);
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
