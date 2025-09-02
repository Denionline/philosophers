/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:06:49 by dximenes          #+#    #+#             */
/*   Updated: 2025/08/28 12:22:56 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*worker(void	*args)
{
	t_head	*head = (t_head *)args;
	printf("%ld\n", head->philo_info.number_of_philos);
	printf("%ld\n", head->philo_info.time_to_die);
	printf("%ld\n", head->philo_info.time_to_eat);
	printf("%ld\n", head->philo_info.time_to_sleep);
	return (NULL);
}

int	philosophers(t_head *head)
{
	// pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_t	thread;


	if (pthread_create(&thread, NULL, worker, head) != 0)
	{
		perror("Erro thread");
	}
	pthread_join(thread, NULL);
	printf("Finished the threads\n");
	return (0);
}