#include "philosophers.h"

long get_current_time_ms() 
{
    struct timeval tv;
    gettimeofday(&tv, (void *)0);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

long time_diff(long start, long end)
{
    return(end - start);
}

void	ft_sleep(long time, t_philo *philosopher)
{
	long    current_time;

	current_time = get_current_time_ms();
	while (1)
	{
		if ((get_current_time_ms() - current_time) >= time)
			break ;
		usleep(philosopher->rules->philo_number * 2);
	}
}