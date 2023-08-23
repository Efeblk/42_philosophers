#include "philosophers.h"

pthread_mutex_t *createfork(int fork_number)
{
    pthread_mutex_t *forks;

    forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * fork_number);
    int i;
    i = 0;
    while (i < fork_number)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    return(forks);
}

pthread_t *createthread(int thread_number, t_philo *philosophers)
{
    pthread_t *threads;

    threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_number);
    int i;
    i = 0;
    while (i < thread_number)
    {
        pthread_create(&threads[i], NULL, philosopher_thread, &philosophers[i]);
        usleep(10);
        i++;
    }
    return(threads);
}

t_philo *createphilo(int philo_number, pthread_mutex_t* forks, t_rules *rules)
{
    t_philo *philosophers;
    int i;

    philosophers = (t_philo *)malloc(sizeof(t_philo) * philo_number);
    i = 0;
    while (i < philo_number)
    {
        philosophers[i].philo_index = i;
        philosophers[i].leftfork = &forks[i];
        philosophers[i].rightfork = &forks[(i + 1) % philo_number];
        philosophers[i].death_time = rules->death_time;
        philosophers[i].eating_time = rules->eating_time;
        philosophers[i].thinking_time = rules->thinking_time;
        philosophers[i].is_dead = 0;
        i++;
    }
    return(philosophers);
}

t_rules *createrules(t_rules* rules, char *argv[])
{
    rules = (t_rules *)malloc(sizeof(t_rules));
    rules->philo_number = ft_atoi(argv[1]);
    rules->death_time = ft_atoi(argv[2]);
    rules->eating_time = ft_atoi(argv[3]);
    rules->thinking_time = ft_atoi(argv[4]);
    if (argv[5])
        rules->nbreat = ft_atoi(argv[5]);
    else
        rules->nbreat = 0;
    return(rules);
}