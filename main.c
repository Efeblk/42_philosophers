#include "philosophers.h"

void* philosopher_thread(void* arg) 
{
    t_philo* philosopher = (t_philo*)arg;

    while (1) {
        long start_time = get_current_time_ms();
        pthread_mutex_lock(philosopher->leftfork);
        printf("Philosopher %d has taken left fork\n", philosopher->philo_index);
        pthread_mutex_lock(philosopher->rightfork);
        printf("Philosopher %d has taken right fork\n", philosopher->philo_index);
        long end_time = get_current_time_ms();
        long elapsed_time = end_time - start_time;
        long remaining_time = philosopher->death_time - elapsed_time;
        if (remaining_time <= 0) 
        {
            philosopher->is_dead = 1;
            pthread_mutex_unlock(philosopher->leftfork);
            pthread_mutex_unlock(philosopher->rightfork);
            return NULL; // Exit the thread
        }
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

int main(int argc, char* argv[]) 
{
    t_rules *rules;
    int i;
    pthread_mutex_t *forks; 
    t_philo *philosophers;
    pthread_t *philosopher_threads;

    if (argc < 5)
        return(1);
    if (argcheck(argv))
        return(1);
    rules = createrules(rules, argv);
    forks = createfork(rules->philo_number);
    philosophers = createphilo(rules->philo_number, forks, rules);
    philosopher_threads = createthread(rules->philo_number, philosophers);

    while (1) {
        i = 0;
        while (philosophers[i].is_dead == 0)
        {
           i++;
           if (i == rules->philo_number)
            break;
        }
        if (philosophers[i].is_dead == 1)
        {
            printf("philo %i is dead bro :( ", philosophers[i].philo_index);
            return(1);
        }  
        usleep(10); // Sleep for 1 second
    }

    i = 0;
    while (i < rules->philo_number) {
        pthread_join(philosopher_threads[i], NULL);
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    free(forks);
    return 0;
}

