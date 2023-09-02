#include "philosophers.h"

static int check_dying(long remaining_time, t_philo *philosopher)
{
    //printf("\n %ld \n \n", remaining_time);
    if (remaining_time <= 0) 
    {
        philosopher->is_dead = 1;
        pthread_mutex_unlock(philosopher->leftfork);
        pthread_mutex_unlock(philosopher->rightfork);
        return 1;
    }
    return 0;
}

static void fork_lock(t_philo *philosopher)
{
    long time;
    time = get_current_time_ms() - philosopher->rules->start_time;
    pthread_mutex_lock(philosopher->leftfork);
    printf("%ld Philosopher %d has taken left fork\n", time, philosopher->philo_index);
    pthread_mutex_lock(philosopher->rightfork);
    printf("%ld Philosopher %d has taken right fork\n", time, philosopher->philo_index);
}

static void fork_unlock(t_philo *philosopher)
{
    long time = get_current_time_ms() - philosopher->rules->start_time;
    pthread_mutex_unlock(philosopher->rightfork);
    printf("%ld Philosopher %d released left fork\n", time, philosopher->philo_index);
    pthread_mutex_unlock(philosopher->leftfork);
    printf("%ld Philosopher %d released right fork\n", time, philosopher->philo_index);
}

static void philo_eat (t_philo *philosopher)
{
    long time = get_current_time_ms() - philosopher->rules->start_time;

    printf("%ld Philosopher %d is eating\n", time, philosopher->philo_index);

    philosopher->last_eat_time = get_current_time_ms();
    ft_sleep(philosopher->rules->eating_time, philosopher);
    //usleep(philosopher->rules->eating_time * 1000);
    if (philosopher->meal_count > 0)
        philosopher->meal_count += 1;
}

static void philo_sleep(t_philo *philosopher)
{   
    long time = get_current_time_ms() - philosopher->rules->start_time;
    printf("%ld Philosopher %d is sleeping\n", time, philosopher->philo_index);
    ft_sleep(philosopher->rules->sleeping_time, philosopher);
    //usleep(philosopher->rules->sleeping_time * 1000);
}

void* philosopher_thread(void* arg) 
{
    t_philo* philosopher = (t_philo*)arg;
    long start_time;
    long end_time;
    long elapsed_time;
    long remaining_time;
    long time;

    if (philosopher->philo_index % 2 != 0 && philosopher->rules->philo_number > 1)
        usleep(philosopher->rules->eating_time * 1000);

    while (1) {
        time = (get_current_time_ms() - philosopher->last_eat_time);
        if (time >= philosopher->rules->death_time)
        {
            philosopher->is_dead = 1;
        }
        printf("\n%i time : %ld\n \n", philosopher->philo_index, time);
        fork_lock(philosopher);
        philo_eat(philosopher);
        fork_unlock(philosopher);
        philo_sleep(philosopher);

        time = get_current_time_ms() - philosopher->rules->start_time;
        printf("%ld Philosopher %d is thinking\n", time, philosopher->philo_index);
    }
    return NULL;
}

