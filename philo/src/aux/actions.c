/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:56:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 11:55:53 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_think(t_philo **philo, time_t time_now)
{
	print_actions((*philo)->head, (*philo)->id, time_now, THINK);
}

static void	action_eat(t_philo **philo, time_t time_now)
{
	// mutex_handle(&(*philo)->head->mutex, LOCK);
	(*philo)->last_meal = time_now;
	(*philo)->meals += 1;
	// mutex_handle(&(*philo)->head->mutex, UNLOCK);
	print_actions((*philo)->head, (*philo)->id, time_now, EAT);
	precise_sleep((*philo)->head->time_to.eat);
}

static void	action_sleep(t_philo **philo, time_t time_now)
{
	print_actions((*philo)->head, (*philo)->id, time_now, SLEEP);
	precise_sleep((*philo)->head->time_to.sleep);
}

static void	action_die(t_philo **philo, time_t time_now)
{
	print_actions((*philo)->head, (*philo)->id, time_now, DIE);
}

void	actions(t_philo *philo, enum e_actions action)
{
	time_t	time_now;

	if (is_simulation_finished(philo->head))
		return ;
	time_now = get_time_now(MILISECONDS);
	if (action == THINK)
		return (action_think(&philo, time_now));
	if (action == EAT)
		return (action_eat(&philo, time_now));
	if (action == SLEEP)
		return (action_sleep(&philo, time_now));
	if (action == DIE)
		return (action_die(&philo, time_now));
}
