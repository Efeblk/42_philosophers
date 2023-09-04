/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:37 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/04 04:00:17 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, (void *)0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(long time, t_rules *rules)
{
	long	current_time;

	current_time = get_current_time_ms();
	while (1)
	{
		if ((get_current_time_ms() - current_time) >= time)
			break ;
		usleep(rules->philo_number * 2);
	}
}
