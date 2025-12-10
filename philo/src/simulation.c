/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:57:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/10 19:59:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	hold_forks(t_philo *philo, t_mutex *fork1, t_mutex *fork2)
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
	usleep(!(philo->id % 2) * 1e3);
	while (!is_simulation_finished(philo->head))
	{
		if (!manage_forks(philo, LOCK))
			break ;
		actions(philo, EAT);
		manage_forks(philo, UNLOCK);
		actions(philo, SLEEP);
		actions(philo, THINK);
		usleep((philo->head->n_philos % 2 && philo->id % 2) * 1e3);
	}
	if (philo->is_dead)
		actions(philo, DIE);
	return (NULL);
}

static int	single_routine(t_philo *philo)
{
	actions(philo, SLEEP);
	actions(philo, THINK);
	actions(philo, DIE);
	return (0);
}

int	simulation(t_head *head, t_philo *philos)
{
	int	pos;
	int	i;

	if (head->n_philos == 1)
		return (single_routine(philos));
	pos = 0;
	while (pos < head->n_philos)
	{
		if (pthread_create(&philos[pos].thread, NULL, routine, &philos[pos]))
		{
			head->philos->is_dead = TRUE;
			handle_errors(ERR_THREAD);
			break ;
		}
		pos++;
	}
	i = 0;
	while (i < pos)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
