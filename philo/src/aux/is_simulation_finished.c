/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simulation_finished.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:07:29 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/06 16:15:17 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_bool	is_simulation_finished(t_head *head)
{
	t_philo	*philos;
	int		all_meals;
	int		i;

	all_meals = 0;
	philos = head->philos;
	i = 0;
	while (!head->is_simulation_finished && i < head->n_philos)
	{
		if (head->meals_limit > 0 && philos[i].meals >= head->meals_limit)
			all_meals += 1;
		if (philos[i].is_dead)
			head->is_simulation_finished = TRUE;
		i++;
	}
	if (all_meals == head->n_philos)
		head->is_simulation_finished = TRUE;
	return (head->is_simulation_finished);
}
