#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define FORK "%ld Philosopher %d has taken fork\n"
# define DEAD "%ld Philosopher %i is dead\n"
# define RL_FORK "%ld Philosopher %d released fork\n"
# define EATING "%ld Philosopher %d is eating\n"
# define SLEEPING "%ld Philosopher %d is sleeping\n"
# define THINKING "%ld Philosopher %d is thinking\n"
typedef struct s_rules
{
    long start_time;
    int philo_number;
    int death_time;
    int eating_time;
    int sleeping_time;
    int nbreat;
    int b_eat;
}t_rules;
typedef struct s_philo
{
    int philo_index;
    pthread_mutex_t *leftfork;
    pthread_mutex_t *rightfork;
    int meal;
    int is_dead;
    long last_eat_time;
    t_rules *rules;
}t_philo;

void* philosopher_thread(void* arg);

pthread_mutex_t *createfork(int fork_number);
pthread_t *createthread(int thread_number, t_philo *philosophers);
t_philo *createphilo(int philo_number, pthread_mutex_t* forks, t_rules *rules);
t_rules *createrules(t_rules* rules, char *argv[]);
int argcheck(char *argv[]);
int ft_atoi(const char *str);
void	ft_sleep(long time, t_philo *philosopher);
long get_current_time_ms();
int main_check(t_philo *philosophers, t_rules *rules);
void join_threads(t_rules *rules, pthread_t *philosopher_threads, pthread_mutex_t *forks);
void detach_threads(t_rules *rules, pthread_t *philosopher_threads, pthread_mutex_t *forks);
void freeer(t_rules *rules, t_philo *philosophers, pthread_mutex_t *forks, pthread_t *philosopher_threads);

#endif 