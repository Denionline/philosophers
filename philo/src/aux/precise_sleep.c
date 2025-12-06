/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:54:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/06 15:01:23 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	precise_sleep(long long milisec, t_head *head)
{
	long long	start;
	long long	target_us;
	long long	elapsed_us;
	long long	remain_us;

	(void)head;
	start = get_time_now(MILISECONDS);
	target_us = milisec * 1e3;
	while ((get_time_now(MILISECONDS) - start) < milisec)
	{
		elapsed_us = (get_time_now(MILISECONDS) - start) * 1000LL;
		remain_us = target_us - elapsed_us;
		if (remain_us > 2000)
			usleep((unsigned int)(remain_us / 2));
		else
			usleep(100);
	}
}
