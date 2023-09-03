#include "philosophers.h"

int main_check(t_philo *philosophers, t_rules *rules)
{
    int total_meals_eaten;
    long time;
    int i;
    int j;

    while (1) 
    {
        i = 0;
        while (i < rules->philo_number)
        {
            time = (get_current_time_ms() - philosophers[i].last_eat_time);
            if (time >= philosophers[i].rules->death_time)
            {
                philosophers[i].is_dead = 1;
                printf("Philosopher %i is dead\n", philosophers[i].philo_index);
                return 1;
            }
            if (rules->check_eat_count && (philosophers[i].meal_count >= rules->nbreat))
                return 0;
            i++;
        }
        usleep(10);
    }
}

void join_threads(t_rules *rules, pthread_t *philosopher_threads, pthread_mutex_t *forks)
{
    int i;
    i = 0;
    while (i < rules->philo_number) 
    {
        pthread_join(philosopher_threads[i], NULL);
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
}

void detach_threads(t_rules *rules, pthread_t *philosopher_threads, pthread_mutex_t *forks)
{
    int i;
    i = 0;
    while (i < rules->philo_number) 
    {
        pthread_detach(philosopher_threads[i]);
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
}

void freeer(t_rules *rules, t_philo *philosophers, pthread_mutex_t *forks, pthread_t *philosopher_threads)
{ 
    free(rules);
    free(philosophers);
    free(forks);
    free(philosopher_threads);
}