/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:06:49 by dximenes          #+#    #+#             */
/*   Updated: 2025/11/28 18:12:20 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void	*args)
{
	const t_philo	philo = *(t_philo *)(args);

	printf("philo [%d] [%ld] -> have take a fork\n", philo.id, get_time());
	printf("philo [%d] [%ld] -> have take a fork\n", philo.id, get_time());
	usleep(1000);
	printf("philo [%d] [%ld] -> start to eat\n", philo.id, get_time());
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
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}
