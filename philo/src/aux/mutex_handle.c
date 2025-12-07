/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:15:02 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 22:42:45 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_handle(t_mutex *mutex, enum e_mutex_action action)
{
	if (mutex)
	{
		if (action == LOCK)
			return (pthread_mutex_lock(mutex));
		if (action == UNLOCK)
			return (pthread_mutex_unlock(mutex));
	}
	return (-1);
}
