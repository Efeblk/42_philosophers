#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_rules
{
    int philo_number;
    int death_time;
    int eating_time;
    int thinking_time;
    int nbreat;
}t_rules;
typedef struct s_philo
{
    int philo_index;
    pthread_mutex_t *leftfork;
    pthread_mutex_t *rightfork;
    int death_time;
    int eating_time;
    int thinking_time;
    int is_dead;
}t_philo;

void* philosopher_thread(void* arg);

pthread_mutex_t *createfork(int fork_number);
pthread_t *createthread(int thread_number, t_philo *philosophers);
t_philo *createphilo(int philo_number, pthread_mutex_t* forks, t_rules *rules);
t_rules *createrules(t_rules* rules, char *argv[]);

long get_current_time_ms();

int argcheck(char *argv[]);

int ft_atoi(const char *str);
#endif 