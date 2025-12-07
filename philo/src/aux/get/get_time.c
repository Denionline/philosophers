/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:10:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 11:19:22 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time_now(enum e_seconds type)
{
	struct timeval	time;

	(void)type;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
	// if (type == MILISECONDS)
	// 	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
	// if (type == SECONDS)
	// 	return (time.tv_sec + (time.tv_usec / 1e6));
	// if (type == MICROSECONDS)
	// 	return ((time.tv_sec * 1e6) + time.tv_usec);
	// return (-1);
}
