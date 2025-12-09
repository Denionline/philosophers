/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:57:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 17:59:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	release_forks(t_philo *philo)
{
	
}

static void	hold_forks(t_philo *philo)
{
	
}

static void	*monitor(void *args)
{
	t_philo	*philo;
	long	time_now;
	long	diff;

	philo = (t_philo *)args;
	while (TRUE)
	{
		time_now = get_time_now(MILISECONDS);
		diff = time_now - philo->last_meal;
		if (diff > philo->head->time_to.die)
		{
			sem_wait(philo->head->print);
			print_actions(philo->head, philo->id, time_now, DIE);
			sem_post(philo->head->dead);
			end(philo->head, SOMEONE_DIED, NULL);
		}
	}
}

int	routine(t_philo *philo)
{
	pthread_t	philo_monitor;

	pthread_create(&philo_monitor, NULL, monitor, philo);
	
	while (TRUE)
	{
		hold_forks(philo);
		actions(philo, EAT);
		release_forks(philo);
		actions(philo, SLEEP);
		actions(philo, THINK);
	}
}

int	simulation(t_head *head)
{
	int	i;

	i = 0;
	while (i < head->n_philos)
	{
		head->philos_pid[i] = fork();
		if (!head->philos_pid[i])
			exit(routine(&head->philos[i]));
	}
	return (0);
}
