/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:32:59 by eriviere          #+#    #+#             */
/*   Updated: 2024/11/21 15:33:02 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

void	precise_usleep(long ms)
{
	long	start;

	start = gettime();
	while (gettime() - start < ms)
		usleep(100);
}

bool	is_dead(t_philo *philo)
{
	long	elapsed;
	long	now;
	long	last_meal;

	last_meal = philo->lm_t;
	now = gettime();
	elapsed = now - last_meal;
	if (elapsed > philo->table->tto_die)
	{
		set_bool(&philo->philo_mtx, &philo->dead, true);
		return (1);
	}
	return (0);
}

void	cleanup_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->philos[i].philo_mtx);
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&table->table_mtx);
	pthread_mutex_destroy(&table->print_mtx);
	free(table->philos);
	free(table->forks);
}

bool	is_digit(const char *str)
{
	if (str[0] >= '0' && str[0] <= '9')
		return (1);
	else if (str[0] == '+' && (str[1] >= '0' && str[1] <= '9'))
		return (1);
	return (0);
}
