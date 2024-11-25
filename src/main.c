/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:31:43 by eriviere          #+#    #+#             */
/*   Updated: 2024/11/21 15:31:46 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!correct_input(argc, argv))
		error_exit(ARGS_ERROR);
	else
	{
		init_data(&table, argv);
		start_simulation(&table);
		cleanup_table(&table);
		exit(EXIT_SUCCESS);
	}
}
