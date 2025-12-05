/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simulation_finished.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:07:29 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/05 16:05:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_bool	is_simulation_finished(t_head *head)
{
	int	i;

	i = 0;
	while (!head->is_simulation_finished && i < head->n_philos)
	{
		if (head->philos[i].meals >= head->meals_limit)
			head->is_simulation_finished = TRUE;
		else if (head->philos[i].is_dead)
			head->is_simulation_finished = TRUE;
		i++;
	}
	return (head->is_simulation_finished);
}
