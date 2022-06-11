/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:22:31 by hfast             #+#    #+#             */
/*   Updated: 2022/06/10 18:25:28 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define    PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					index;
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					count_eat;
	long long			last_lunch;
	long long			born_time;
	long long			die_time;
	int					count_of_lunch;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*print;
	struct s_table		*table;
	int					*death;
}		t_philo;

typedef struct s_table
{
	int					numb_philos;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	long long			time_to_start;
	int					numb_of_lunch;
	pthread_t			*threads;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	t_philo				*philosopher;
	int					*count;
	int					*death;
}	t_table;

int			check(int argc, char **argv);
long long	ft_atoi(const char *str);
void		init_table(int argc, char **argv, t_table *s_table);
void		memory_for_all(t_table *table);
void		init_philos(t_table *table);
void		*philo_life(void *link);
void		thread_start(t_table *table);
long long	get_timestamp(void);
void		ft_mutex_destroy(t_table *table);
int			ft_free(t_table *table);
void		philo_eating(t_table *table, t_philo *philo);
void		philo_sleeping(t_table *table, t_philo *philo);
void		philo_thinking(t_table *table, t_philo *philo);
void		philo_print(t_table *table, t_philo *philo, char *event);

#endif