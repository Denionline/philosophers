/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:56:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/05 17:43:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_think(t_philo **philo, time_t time_now)
{
	print_actions((*philo)->head, (*philo)->id, time_now, THINK);
}

static void	action_eat(t_philo **philo, time_t time_now)
{
	if ((time_now - (*philo)->last_meal) > (*philo)->head->time_to.die)
		(*philo)->is_dead = TRUE;
	else
	{
		(*philo)->meals += 1;
		(*philo)->last_meal = time_now;
		print_actions((*philo)->head, (*philo)->id, time_now, EAT);
		precise_sleep((*philo)->head->time_to.eat, (*philo)->head);
	}
}

static void	action_sleep(t_philo **philo, time_t time_now)
{
	print_actions((*philo)->head, (*philo)->id, time_now, SLEEP);
	precise_sleep((*philo)->head->time_to.sleep, (*philo)->head);
}

static void	action_die(t_philo **philo, time_t time_now)
{
	print_actions((*philo)->head, (*philo)->id, time_now, DIE);
}

void	actions(t_philo *philo, enum e_actions action)
{
	time_t	time_now;

	if (!is_simulation_finished(philo->head))
	{
		time_now = get_time_now(MILISECONDS);
		if (action == THINK)
			action_think(&philo, time_now);
		else if (action == EAT)
			action_eat(&philo, time_now);
		else if (action == SLEEP)
			action_sleep(&philo, time_now);
		if (philo->is_dead)
			action_die(&philo, time_now);
	}
}
