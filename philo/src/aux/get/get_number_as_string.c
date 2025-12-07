/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_as_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:08:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 15:40:20 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_getsize(long nbr)
{
	int	i;

	i = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	get_number_as_string(long n, char *buff)
{
	int	size;

	size = ft_getsize(n);
	buff[size] = '\0';
	while (size > 0)
	{
		buff[--size] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (0);
}
