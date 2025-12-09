/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:57:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 14:48:28 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_head *head, int id)
{
	thread
}

int	simulation(t_head *head)
{
	int	pid;
	int	i;

	i = 0;
	while (i < head->n_philos)
	{
		pid = fork();
		if (!pid)
			routine(head, i + 1);
		else
			head->philos_pid[i] = pid;
	}
	return (0);
}
