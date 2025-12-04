/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:57:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/04 13:58:49 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	release_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		print_actions(&philo->head->print, get_time(), philo->id, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		print_actions(&philo->head->print, get_time(), philo->id, FORK);
	}
}

static void	*routine(void	*args)
{
	const t_philo	*philo = (t_philo *)(args);

	if (!(philo->id % 2))
		usleep(1000);
	while (!philo->head->someone_died)
	{
		action_think(philo);
		take_forks(philo);
		action_eat(philo);
		release_forks(philo);
		action_sleep(philo);
	}
	return (NULL);
}

int	philosophers(t_philo *philos)
{
	int	i;

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
