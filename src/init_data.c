/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:31:27 by eriviere          #+#    #+#             */
/*   Updated: 2024/11/21 15:31:31 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_philo *philo, t_fork *forks)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->second_fork = &forks[philo->id - 1];
	philo->first_fork = &forks[(philo->id) % philo_nbr];
	if ((philo->id % 2) == 0)
	{
		philo->first_fork = &forks[philo->id - 1];
		philo->second_fork = &forks[(philo->id) % philo_nbr];
	}
}

static void	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->meals = 0;
		philo->full = false;
		philo->dead = false;
		philo->table = table;
		pthread_mutex_init(&philo->philo_mtx, NULL);
		init_forks(philo, table->forks);
		i++;
	}
}

void	init_data(t_table *table, char **argv)
{
	int	i;

	i = 0;
	table->philo_nbr = ft_atol(argv[1]);
	table->tto_die = ft_atol(argv[2]);
	table->tto_eat = ft_atol(argv[3]);
	table->tto_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->min_meals = ft_atol(argv[5]);
	else
		table->min_meals = -1;
	table->philo_dead = false;
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	while (i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i].fork, NULL);
		table->forks[i].id = i;
		i++;
	}
	pthread_mutex_init(&table->table_mtx, NULL);
	pthread_mutex_init(&table->print_mtx, NULL);
	init_philo(table);
}
