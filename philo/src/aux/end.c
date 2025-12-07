/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:48:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 18:29:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end(t_head *head)
{
	int	i;

	i = 0;
	while (i < head->n_philos)
		pthread_mutex_destroy(&head->forks[i++]);
	pthread_mutex_destroy(&head->mutex);
	pthread_mutex_destroy(&head->print);
	free(head->forks);
	free(head->philos);
	free(head);
	return (0);
}
