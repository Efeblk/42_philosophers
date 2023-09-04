/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:08:57 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/04 04:19:44 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine_helper(t_philo *philo)
{
	if (!check_dd(philo->rules))
		fork_lock(philo);
	if (!check_dd(philo->rules))
		philo_eat(philo);
	if (!check_dd(philo->rules))
		fork_unlock(philo);
}

void	routine_sl_th(t_philo *philo)
{
	long	time;

	if (!check_dd(philo->rules))
		philo_sleep(philo);
	if (!check_dd(philo->rules))
	{
		time = get_current_time_ms() - philo->rules->start_time;
		printf(THINKING, time, philo->philo_index);
	}
}

int	check_dying(long remaining_time, t_philo *philosopher)
{
	if (remaining_time <= 0)
	{
		pthread_mutex_unlock(philosopher->leftfork);
		pthread_mutex_unlock(philosopher->rightfork);
		return (1);
	}
	return (0);
}

int	check_dd(t_rules *rules)
{
	pthread_mutex_lock(rules->death);
	if (rules->p_dead)
	{
		pthread_mutex_unlock(rules->death);
		return (1);
	}
	pthread_mutex_unlock(rules->death);
	return (0);
}
