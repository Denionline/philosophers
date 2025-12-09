/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_as_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:08:55 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 13:17:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_string_as_number(char *n)
{
	int		size;
	long	res;

	while ((*n >= '\t' && *n <= '\r') || *n == ' ')
		n++;
	if ((*n == '+' || *n == '-'))
		if (*(n++) == '-')
			return (-1);
	size = 0;
	res = 0;
	while (*n && (*n >= '0' && *n <= '9') && size < 20)
	{
		res = (res * 10) + (*(n++) - '0');
		size++;
	}
	if (size == 20)
		return (-1);
	return (res);
}
