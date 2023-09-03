#include "philosophers.h"

int	check_dying(long remaining_time, t_philo *philosopher)
{
	if (remaining_time <= 0)
	{
		philosopher->is_dead = 1;
		pthread_mutex_unlock(philosopher->leftfork);
		pthread_mutex_unlock(philosopher->rightfork);
		return (1);
	}
	return (0);
}

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, (void *)0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(long time, t_philo *philosopher)
{
	long	current_time;

	current_time = get_current_time_ms();
	while (1)
	{
		if ((get_current_time_ms() - current_time) >= time)
			break ;
		usleep(philosopher->rules->philo_number * 2);
	}
}
