/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:28:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/08/28 12:18:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse(t_head **head, char *args[], int len)
{
	if (len < 4 || len > 5)
		return (1);
	(*head) = malloc(sizeof(t_head));
	if (!(*head))
		return (1);
	memset(*head, 0, sizeof(**head));
	(*head)->philo_info.number_of_philos = ft_atol(args[0]);
	(*head)->philo_info.time_to_die = ft_atol(args[1]);
	(*head)->philo_info.time_to_eat = ft_atol(args[2]);
	(*head)->philo_info.time_to_sleep = ft_atol(args[3]);
	if (len == 5)
		(*head)->philo_info.limit_times_to_eat = ft_atol(args[4]);
	return (0);
}