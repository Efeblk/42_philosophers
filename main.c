#include "philosophers.h"

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
            printf("%i\n", philosophers[i].philo_index);
            printf("philo %i is dead", philosophers[i].philo_index);
            return(1);
        }  
        usleep(10);
    }
    i = 0;
    while (i < rules->philo_number) 
    {
        pthread_join(philosopher_threads[i], NULL);
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    free(forks);
    return 0;
}

