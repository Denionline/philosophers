/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:28:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/11/28 18:24:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*get_philos(t_info info)
{
	t_philo	*philos;
	int		i;

	philos = calloc(info.number_of_philos + 1, sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < info.number_of_philos)
	{
		philos[i] = (t_philo){
			.id = (i + 1),
			.info = info,
			.exists = TRUE,
		};
		i++;
	}
	philos[i] = (t_philo){.exists = FALSE};
	return (philos);
}

int	parse(t_head **head, char *args[], int len)
{
	t_info	info;

	if (len < 4 || len > 5)
		return (1);
	(*head) = calloc(1, sizeof(t_head));
	if (!(*head))
		return (1);
	info = (t_info){
		.number_of_philos = ft_atol(args[0]),
		.time_to_die = ft_atol(args[1]),
		.time_to_eat = ft_atol(args[2]),
		.time_to_sleep = ft_atol(args[3]),
		.limit_to_eat = -1,
	};
	if (len == 5)
		info.limit_to_eat = ft_atol(args[4]);
	(*head)->philos = get_philos(info);
	pthread_mutex_init(&(*head)->mutex, NULL);
	return (0);
}
