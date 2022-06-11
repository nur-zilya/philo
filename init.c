/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:11:22 by hfast             #+#    #+#             */
/*   Updated: 2022/06/10 18:17:09 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(int argc, char **argv, t_table *table)
{
	table->numb_philos = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	table->time_to_start = 0;
	if (argc == 6)
		table->numb_of_lunch = ft_atoi(argv[5]);
	else
		table->numb_of_lunch = -1;
}

void	memory_for_all(t_table *table)
{
	table->philosopher = malloc(sizeof(t_philo) * table->numb_philos);
	table->fork = malloc(sizeof(pthread_mutex_t) * table->numb_philos);
	table->threads = malloc(sizeof(pthread_t) * table->numb_philos);
	table->death = malloc(sizeof(int *));
	table->count = malloc(sizeof(int *));
	*table->death = 0;
	*table->count = 0;
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->numb_philos)
	{
		table->philosopher[i].index = i;
		table->philosopher[i].time_to_die = table->time_die;
		table->philosopher[i].time_to_eat = table->time_eat;
		table->philosopher[i].time_to_sleep = table->time_sleep;
		table->philosopher[i].left_fork = &table->fork[i];
		table->philosopher[i].print = &table->print;
		table->philosopher[i].philo_num = table->numb_philos;
		table->philosopher[i].last_lunch = 0;
		table->philosopher[i].count_eat = 0;
		table->philosopher[i].count_of_lunch = table->numb_of_lunch;
		if (i == table->numb_philos - 1)
			table->philosopher[i].right_fork = &table->fork[0];
		else
			table->philosopher[i].right_fork = &table->fork[i + 1];
		i++;
	}
	i = 0;
	while (i < table->numb_philos)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print, NULL);
}
