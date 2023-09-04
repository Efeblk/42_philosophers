/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:28 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/04 04:08:35 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*createfork(int fork_number)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * fork_number);
	i = 0;
	while (i < fork_number)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

pthread_t	*createthread(int thread_number, t_philo *philosophers)
{
	pthread_t	*threads;
	int			i;
	long		time;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_number);
	time = get_current_time_ms();
	philosophers->rules->start_time = time;
	i = 0;
	while (i < thread_number)
	{
		pthread_create(&threads[i], NULL, philosopher_thread, &philosophers[i]);
		usleep(1);
		i++;
	}
	return (threads);
}

t_philo	*createphilo(int philo_number, pthread_mutex_t *f, t_rules *r)
{
	t_philo	*philosophers;
	int		i;

	philosophers = (t_philo *)malloc(sizeof(t_philo) * philo_number);
	i = 0;
	while (i < philo_number)
	{
		philosophers[i].philo_index = i + 1;
		philosophers[i].leftfork = &f[i];
		philosophers[i].rightfork = &f[(i + 1) % philo_number];
		philosophers[i].meal = 0;
		philosophers[i].rules = r;
		philosophers[i].last_eat_time = get_current_time_ms();
		i++;
	}
	return (philosophers);
}

t_rules	*createrules(t_rules *rules, char *argv[])
{
	rules = (t_rules *)malloc(sizeof(t_rules));
	rules->death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(rules->death, NULL);
	rules->p_dead = 0;
	rules->philo_number = ft_atoi(argv[1]);
	rules->death_time = ft_atoi(argv[2]);
	rules->eating_time = ft_atoi(argv[3]);
	rules->sleeping_time = ft_atoi(argv[4]);
	if (argv[5])
	{
		rules->nbreat = ft_atoi(argv[5]);
		rules->b_eat = 1;
	}
	else
	{
		rules->nbreat = 0;
		rules->b_eat = 0;
	}
	return (rules);
}
