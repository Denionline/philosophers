/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:48:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 17:00:13 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"



int	end(t_head *head, int code, char *description)
{
	int	i;

	i = 0;
	free(head);
	if (code)
		exit (code);
	exit (0);
}
