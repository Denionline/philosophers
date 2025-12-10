/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:59:16 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/10 19:28:39 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_message(enum e_actions action)
{
	if (action == FORK)
		return ("has taken a fork");
	if (action == EAT)
		return ("is eating");
	if (action == SLEEP)
		return ("is sleeping");
	if (action == THINK)
		return ("is thinking");
	if (action == DIE)
		return ("died");
	return (NULL);
}

static void	put_in_buff(char *string, char *buff, int *pos)
{
	int	j;
	int	i;

	j = *pos;
	i = 0;
	while (string[i])
		buff[j++] = string[i++];
	*pos = j;
}

static void	print_buff(char *buff, int size)
{
	int	i;

	i = 0;
	while (i < size)
		write(1, &buff[i++], 1);
}

void	print_actions(t_head *head, int idx, time_t time_now, int action)
{
	char	buff[9999];
	char	time[20];
	char	id[20];
	int		pos;

	mutex_handle(&head->print, LOCK);
	if (get_number_as_string(idx, id, 0))
		return ;
	if (get_number_as_string(time_now - head->start_time, time, 6))
		return ;
	pos = 0;
	put_in_buff(time, buff, &pos);
	put_in_buff(" ", buff, &pos);
	put_in_buff(id, buff, &pos);
	put_in_buff(" ", buff, &pos);
	put_in_buff(get_message(action), buff, &pos);
	put_in_buff("\n", buff, &pos);
	print_buff(buff, pos);
	mutex_handle(&head->print, UNLOCK);
}
