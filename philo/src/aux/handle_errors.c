/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:39:55 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/07 22:02:07 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_message(enum e_errors code)
{
	if (code == ERR_MALLOC)
		return ("Found malloc error\n");
	if (code == ERR_INVALID_ARGS)
		return ("./philo <n_philo> <time_to_die> <time_to_eat> <time_to_sleep> [limit_to_eat]\n");
	if (code == ERR_N_PHILO_MORE_THAN_LIMIT)
		return ("The limit for number of philosophers is 200\n");
	if (code == ERR_ARG_OUT_OF_LIMIT)
		return ("Argument out of the range between 0 and LONG_MAX \n");
	return (NULL);
}

static void	print_string(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		write(1, &string[i++], 1);
}

int	handle_errors(enum e_errors code)
{
	char	*message;

	message = get_message(code);
	print_string(message);
	return (code);
}
