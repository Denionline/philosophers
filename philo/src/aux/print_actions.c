/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:59:16 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/06 15:00:34 by dximenes         ###   ########.fr       */
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

void	print_actions(t_head *head, int idx, time_t time_now, enum e_actions action)
{
	pthread_mutex_lock(&head->print);
	printf("%06ld %d %s\n", time_now - head->start_time, idx, get_message(action));
	pthread_mutex_unlock(&head->print);
}
