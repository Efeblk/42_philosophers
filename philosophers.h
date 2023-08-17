#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
    int philo_index;
    pthread_mutex_t *leftfork;
    pthread_mutex_t *rightfork;
}t_philo;

#endif 