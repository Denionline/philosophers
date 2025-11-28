/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:48:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/11/24 17:15:08 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int balance = 0;

void	write_balance(int new_balance)
{
	usleep(250000);
	balance = new_balance;
}

int	read_balance()
{
	usleep(250000);
	return (balance);
}

void	*deposit(void *amount)
{
	int account_balance;
	
	account_balance = read_balance();
	account_balance += *((int *) amount);
	write_balance(account_balance);
	return (NULL);
}

int	print(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	int			deposit1 = 300;
	int			deposit2 = 200;
	int			before = read_balance();
	int			after;

	printf("Before: %d\n", before);

	pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
	pthread_create(&thread2, NULL, deposit, (void*) &deposit2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	after = read_balance();
	printf("After: %d\n", after);
	return (0);
}