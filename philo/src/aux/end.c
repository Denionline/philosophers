/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:48:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/05 14:23:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end(t_head *head)
{
	int	i;

	i = 0;
	while (i < head->n_philos)
	{
		free(head->forks);
		free(head->philos);
	}
	free(head);
}
