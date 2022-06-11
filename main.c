/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:56:06 by hfast             #+#    #+#             */
/*   Updated: 2022/06/10 18:17:42 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!check(argc, argv))
		return (0);
	init_table(argc, argv, &table);
	if (table.numb_philos == 1)
	{
		printf("0 1 has taken a left fork\n");
		usleep(1000 * table.time_die);
		printf("%d 1 is died\n", table.time_die);
		return (0);
	}
	memory_for_all(&table);
	init_philos(&table);
	thread_start(&table);
	ft_mutex_destroy(&table);
	ft_free(&table);
}
