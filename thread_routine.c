#include "philosophers.h"

static int check_dying(long remaining_time, t_philo *philosopher)
{
    if (remaining_time <= 0) 
    {
        philosopher->is_dead = 1;
        pthread_mutex_unlock(philosopher->leftfork);
        pthread_mutex_unlock(philosopher->rightfork);
        return 1;
    }
}

static void fork_lock(t_philo *philosopher)
{
    pthread_mutex_lock(philosopher->leftfork);
    printf("Philosopher %d has taken left fork\n", philosopher->philo_index);
    pthread_mutex_lock(philosopher->rightfork);
    printf("Philosopher %d has taken right fork\n", philosopher->philo_index);
}

void* philosopher_thread(void* arg) 
{
    t_philo* philosopher = (t_philo*)arg;

    while (1) {
        long start_time = get_current_time_ms();
        fork_lock(philosopher);
        long end_time = get_current_time_ms();
        long elapsed_time = end_time - start_time;
        long remaining_time = philosopher->death_time - elapsed_time;

        if (check_dying(remaining_time, philosopher))
            return NULL;

        printf("Philosopher %d is eating\n", philosopher->philo_index);
        usleep(philosopher->eating_time * 1000);
        pthread_mutex_unlock(philosopher->leftfork);
        printf("Philosopher %d released left fork\n", philosopher->philo_index);
        pthread_mutex_unlock(philosopher->rightfork);
        printf("Philosopher %d released right fork\n", philosopher->philo_index);
        printf("Philosopher %d is thinking\n", philosopher->philo_index);
        usleep(remaining_time * 1000);
    }
    return NULL;
}

