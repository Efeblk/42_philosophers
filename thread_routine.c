/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:34 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/04 04:11:44 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_lock(t_philo *philosopher)
{
	long	time;

	pthread_mutex_lock(philosopher->leftfork);
	time = get_current_time_ms() - philosopher->rules->start_time;
	printf(FORK, time, philosopher->philo_index);
	pthread_mutex_lock(philosopher->rightfork);
	time = get_current_time_ms() - philosopher->rules->start_time;
	printf(FORK, time, philosopher->philo_index);
}

void	fork_unlock(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->rightfork);
	pthread_mutex_unlock(philosopher->leftfork);
}

void	philo_eat(t_philo *philosopher)
{
	long	time;

	time = get_current_time_ms() - philosopher->rules->start_time;
	printf(EATING, time, philosopher->philo_index);
	philosopher->last_eat_time = get_current_time_ms();
	ft_sleep(philosopher->rules->eating_time, philosopher->rules);
	if (philosopher->rules->nbreat > 0)
		philosopher->meal += 1;
}

void	philo_sleep(t_philo *philosopher)
{
	long	time;

	time = get_current_time_ms() - philosopher->rules->start_time;
	printf(SLEEPING, time, philosopher->philo_index);
	ft_sleep(philosopher->rules->sleeping_time, philosopher->rules);
}

void	*philosopher_thread(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->philo_index % 2 != 0 && philo->rules->philo_number > 1)
		usleep(philo->rules->eating_time * 1000);
	while (1)
	{
		routine_helper(philo);
		if (!check_dd(philo->rules))
		{
			if (philo->rules->b_eat && (philo->meal >= philo->rules->nbreat))
				return (NULL);
		}
		routine_sl_th(philo);
		if (check_dd(philo->rules))
			return (NULL);
	}
	return (NULL);
}
