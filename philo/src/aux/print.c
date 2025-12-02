/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:59:16 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/02 22:42:46 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_actions(long time, int idx, enum e_actions action)
{
	char	message;

	if (action == FORK)
		message =("has taken a fork");
	else if (action == EAT)
		message =("is eating");
	else if (action == SLEEP)
		message =("is sleeping");
	else if (action == THINK)
		message =("is thinking");
	else if (action == DIE)
		message =("died");
	else
		return (1);
	printf("%ld %d %s\n", time, idx, message);
}
