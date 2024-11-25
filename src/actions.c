/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:30:48 by eriviere          #+#    #+#             */
/*   Updated: 2024/11/21 15:30:53 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->second_fork->fork);
	print_status(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	philo->meals++;
	if (philo->meals == philo->table->min_meals)
		philo->full = true;
	philo->lm_t = gettime();
	print_status(philo, "is eating");
	precise_usleep(philo->table->tto_eat);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}

void	to_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	precise_usleep(philo->table->tto_sleep);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
	precise_usleep(5);
}
