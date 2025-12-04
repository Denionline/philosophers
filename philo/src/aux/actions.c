/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:56:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/04 13:55:38 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action_eat(t_philo *philo)
{
	philo->last_meal = get_time();
	//check the limit to each meal
	print_actions(&philo->head->print, get_time(), philo->id, EAT);
	usleep(philo->head->time_to.eat);
}

int	action_die(t_philo *philo)
{
	print_actions(&philo->head->print, get_time(), philo->id, DIE);
}

int	action_sleep(t_philo *philo)
{
	print_actions(&philo->head->print, get_time(), philo->id, SLEEP);
}

int	action_think(t_philo *philo)
{
	print_actions(&philo->head->print, get_time(), philo->id, THINK);
}
