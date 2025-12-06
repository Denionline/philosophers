/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:02:52 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/06 15:07:14 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char *argv[])
{
	t_head	*head;
	char	*test_argv[] = {"./philo", "4", "200", "100", "100"};
	int		test_argc = 5;

	if (argc == 1) {
		argc = test_argc;
		argv = test_argv;
	}
	if (argc < 5 || argc > 6)
	{
		printf("./philo <n_philo> <time_to_die> <time_to_eat> <time_to_sleep> [limit_to_eat]\n");
		return (1);
	}
	if (parse(&head, argv + 1, argc - 1))
		return (1);
	simulation(head, head->philos);
	return (0);
}
