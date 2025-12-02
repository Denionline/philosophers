/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:06:49 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/02 20:55:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	
}

static void	*routine(void	*args)
{
	const t_philo	*philo = (t_philo *)(args);

	if (!(philo->id % 2))
		usleep(1000);
	while (!philo->head->someone_died)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		sleep_philo(philo);
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
