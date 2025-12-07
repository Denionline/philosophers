/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simulation_finished.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:07:29 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 22:33:36 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static enum e_bool	is_starved(t_head *head, t_philo *philo)
{
	time_t	current_time;
	time_t	diff;
	
	current_time = get_time_now(MILISECONDS);
	diff = current_time - philo->last_meal;
	if (diff > head->time_to.die)
		philo->is_dead = TRUE;
	return (philo->is_dead);
}

enum e_bool is_someone_dead(t_philo *philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (philos[i].is_dead)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

enum e_bool	is_simulation_finished(t_head *head)
{
	enum e_bool	is_finished;
	t_philo		*philos;
	int			all_meals;
	int			i;

	is_finished = FALSE;
	all_meals = 0;
	philos = head->philos;
	i = 0;
	mutex_handle(&head->mutex, LOCK);
	while (!is_finished && i < head->n_philos)
	{
		if (is_someone_dead(philos, head->n_philos))
			is_finished = TRUE;
		else if (is_starved(head, &philos[i]))
			is_finished = TRUE;
		else if (head->meals_limit > 0 && philos[i].meals >= head->meals_limit)
			all_meals += 1;
		i++;
	}
	if (all_meals == head->n_philos)
		is_finished = TRUE;
	mutex_handle(&head->mutex, UNLOCK);
	return (is_finished);
}
