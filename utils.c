/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:30:06 by hfast             #+#    #+#             */
/*   Updated: 2022/06/10 18:26:05 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_timestamp(void)
{
	struct timeval	t;
	long long		now;

	gettimeofday(&t, NULL);
	now = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (now);
}

int	check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
		|| (argc == 6 && ft_atoi(argv[5]) <= 0))
	{
		printf("Wrong arguments\n");
		return (0);
	}
	return (1);
}

long long	ft_atoi(const char *str)
{
	int					i;
	int					flag;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	flag = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (-1);
	if (flag == 1 && nbr >= 9223372036854775807u)
		return (-1);
	if (flag == -1 && nbr >= 9223372036854775808u)
		return (0);
	return (nbr * flag);
}

void	ft_mutex_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->numb_philos)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
}

int	ft_free(t_table *table)
{
	free(table->philosopher);
	free(table->fork);
	free(table->threads);
	free(table->death);
	free(table->count);
	return (0);
}
