/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:34 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/03 21:50:35 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_lock(t_philo *philosopher)
{
	long	time;

	time = get_current_time_ms() - philosopher->rules->start_time;
	pthread_mutex_lock(philosopher->leftfork);
	printf(FORK, time, philosopher->philo_index);
	pthread_mutex_lock(philosopher->rightfork);
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
	ft_sleep(philosopher->rules->eating_time, philosopher);
	if (philosopher->rules->nbreat > 0)
		philosopher->meal += 1;
}

void	philo_sleep(t_philo *philosopher)
{
	long	time;

	time = get_current_time_ms() - philosopher->rules->start_time;
	printf(SLEEPING, time, philosopher->philo_index);
	ft_sleep(philosopher->rules->sleeping_time, philosopher);
}

void	*philosopher_thread(void *arg)
{
	t_philo		*philo;
	long		time;

	philo = (t_philo *)arg;
	if (philo->philo_index % 2 != 0 && philo->rules->philo_number > 1)
		usleep(philo->rules->eating_time * 1000);
	while (1)
	{
		fork_lock(philo);
		philo_eat(philo);
		fork_unlock(philo);
		if (philo->rules->b_eat && (philo->meal >= philo->rules->nbreat))
			return (NULL);
		philo_sleep(philo);
		time = get_current_time_ms() - philo->rules->start_time;
		printf(THINKING, time, philo->philo_index);
	}
	return (NULL);
}
