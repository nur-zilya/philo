/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:48:00 by hfast             #+#    #+#             */
/*   Updated: 2022/06/10 18:15:13 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo_print(table, philo, "has taken a left fork");
	pthread_mutex_lock(philo->right_fork);
	philo_print(table, philo, "has taken a right fork");
	philo_print(table, philo, "is eating");
	philo->count_eat++;
	philo->last_lunch = get_timestamp();
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_table *table, t_philo *philo)
{
	philo_print(table, philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
}

void	philo_thinking(t_table *table, t_philo *philo)
{
	philo_print(table, philo, "is thinking");
}

void	philo_print(t_table *table, t_philo *philo, char *event)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d %s\n", get_timestamp() - philo->born_time,
		philo->index + 1, event);
	pthread_mutex_unlock(philo->print);
}
