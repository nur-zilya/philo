/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:15:29 by hfast             #+#    #+#             */
/*   Updated: 2022/06/10 18:21:59 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_check(void *link)
{
	t_table	*table;
	t_philo	*philo;
	int		i;

	i = 0;
	table = link;
	philo = table->philosopher;
	while (1)
	{
		while (i < table->numb_philos)
		{
			if (get_timestamp() - philo[i].last_lunch > philo[i].time_to_die
				&& philo->count_eat != philo->count_of_lunch + 1 \
			&& philo->count_eat != philo->count_of_lunch)
			{
				printf("%lld %d" "is died\n",
					get_timestamp() - philo->born_time, philo->index);
				pthread_mutex_lock(&table->print);
				*table->death = 1;
				return (NULL);
			}
				i++;
		}
		i = 0;
	}
	return (NULL);
}

void	*philo_life(void *link)
{
	t_philo	*philosopher;
	t_table	*table;
	int		i;

	i = 0;
	philosopher = (t_philo *)link;
	table = philosopher->table;
	philosopher->born_time = get_timestamp();
	philosopher->last_lunch = philosopher->born_time;
	while (1)
	{
		if (philosopher->count_eat != philosopher->count_of_lunch)
		{
			philo_eating(table, philosopher);
			philo_sleeping(table, philosopher);
			philo_thinking(table, philosopher);
		}
		else
			break ;
	}
	usleep(1000 * philosopher->time_to_eat);
	philosopher->count_eat++;
	return (NULL);
}

void	thread_start(t_table *table)
{
	int			i;
	pthread_t	watcher;

	i = 0;
	while (i < table->numb_philos)
	{
		pthread_create(&table->threads[i], NULL,
			&philo_life, &table->philosopher[i]);
		i++;
		usleep(100);
	}
	pthread_create(&watcher, NULL, &death_check, table);
	while (*table->death == 0 && (table->philosopher[0].count_eat
			!= table->numb_of_lunch + 1))
		usleep(100);
}
