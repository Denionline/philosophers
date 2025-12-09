/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:02:52 by dximenes          #+#    #+#             */
/*   Updated: 2025/12/09 17:05:14 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_head	*head;

	parse(&head, argv + 1, argc - 1);
	simulation(head);
	end(head, 0, "SUCESS");
	return (0);
}
