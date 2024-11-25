/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:31:55 by eriviere          #+#    #+#             */
/*   Updated: 2024/11/21 18:55:59 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	full_philos(t_table *table)
{
	int	full_philos;
	int	i;

	full_philos = 0;
	i = 0;
	while (i < table->philo_nbr)
	{
		if (get_bool(&table->philos[i].philo_mtx, &table->philos[i].full))
			full_philos++;
		i++;
	}
	if (full_philos == table->philo_nbr)
	{
		set_bool(&table->table_mtx, &table->philo_dead, true);
		return (1);
	}
	return (0);
}

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		usleep(10);
		if (get_bool(&table->table_mtx, &table->philo_dead))
			break ;
		if (table->philo_nbr == 1)
		{
			print_dead(&table->philos[0], "died");
			break ;
		}
		if (&full_philos)
			break ;
	}
	return (NULL);
}
