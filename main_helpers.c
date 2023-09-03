/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:21 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/03 21:52:03 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main_check(t_philo *philosophers, t_rules *rules)
{
	long	time;
	int		i;

	while (1)
	{
		i = 0;
		while (i < rules->philo_number)
		{
			time = (get_current_time_ms() - philosophers[i].last_eat_time);
			if (time >= philosophers[i].rules->death_time)
			{
				philosophers[i].is_dead = 1;
				printf(DEAD, time, philosophers[i].philo_index);
				return (1);
			}
			if (rules->b_eat && (philosophers[i].meal >= rules->nbreat))
				return (0);
			i++;
		}
		usleep(10);
	}
}

void	join_threads(t_rules *r, pthread_t *t, pthread_mutex_t *f)
{
	int	i;

	i = 0;
	while (i < r->philo_number)
	{
		pthread_join(t[i], NULL);
		pthread_mutex_destroy(&f[i]);
		i++;
	}
}

void	detach_threads(t_rules *r, pthread_t *t, pthread_mutex_t *f)
{
	int	i;

	i = 0;
	while (i < r->philo_number)
	{
		pthread_detach(t[i]);
		pthread_mutex_destroy(&f[i]);
		i++;
	}
}

void	fre(t_rules *r, t_philo *p, pthread_mutex_t *f, pthread_t *t)
{
	if (r != NULL)
		free(r);
	if (p != NULL)
		free(p);
	if (f != NULL)
		free(f);
	if (t != NULL)
		free(t);
}
