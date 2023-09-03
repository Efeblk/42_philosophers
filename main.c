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

    int total_meals_eaten = 0; // Initialize total meals eaten to 0
    long time;
    while (1) 
    {
        i = 0;
        while (i < rules->philo_number)
        {
            time = (get_current_time_ms() - philosophers[i].last_eat_time);
            if (time >= philosophers[i].rules->death_time)
                philosophers[i].is_dead = 1;
    
            if (philosophers[i].is_dead)
            {
                printf("Philosopher %i is dead\n", philosophers[i].philo_index);
                return 1;
            }

            total_meals_eaten = 0; 

            int j = 0;
            while (j < rules->philo_number)
            {
                total_meals_eaten += philosophers[j].meal_count;
                j++;
            }

            if (rules->check_eat_count && (total_meals_eaten >= rules->nbreat))
                return 0; // Exit the program
            i++;
        }

        usleep(10);
    }

    i = 0;

    // if (rules->philo_number == 1)
    // {
    //     pthread_detach(philosopher_threads[0]);
    // }
    
    while (i < rules->philo_number) 
    {
        pthread_join(philosopher_threads[i], NULL);
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    free(forks);
    return 0;
}

