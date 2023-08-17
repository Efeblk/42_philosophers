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

