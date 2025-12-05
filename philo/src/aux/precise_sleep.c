/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:54:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/05 14:24:04 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	precise_sleep(long milisec, t_head *head)
{
	long	start;
	long	elapsed;
	long	remain;

	(void)head;
	start = get_time_now(MICROSECONDS);
	while ((get_time_now(MICROSECONDS) - start) < milisec)
	{
		elapsed = get_time_now(MICROSECONDS) - start;
		remain = milisec - elapsed;
		if (remain > 1e3)
			usleep(milisec / 2);
		else
			while ((get_time_now(MICROSECONDS) - start) < milisec)
				;
	}
}
