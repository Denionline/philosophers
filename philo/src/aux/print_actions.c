/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:59:16 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/04 11:34:15 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_message(enum e_actions action)
{
	if (action == FORK)
		return ("has taken a fork");
	if (action == EAT)
		return ("is eating");
	if (action == SLEEP)
		return ("is sleeping");
	if (action == THINK)
		return ("is thinking");
	if (action == DIE)
		return ("died");
	return (NULL);
}

int	print_actions(mutex_t *mutex, long time, int idx, enum e_actions action)
{
	pthread_mutex_lock(mutex);
	printf("%ld %d %s\n", time, idx, get_message(action));
	pthread_mutex_unlock(mutex);
}
