#include "philosophers.h"

#define NUM_PHILOSOPHERS 5

// Function for philosopher thread to simulate eating
void* philosopher_thread(void* arg) {
    t_philo* philosopher = (t_philo*)arg;

    while (1) {

        pthread_mutex_lock(philosopher->leftfork);
        printf("Philosopher %d picked up left fork\n", philosopher->philo_index);
            
        pthread_mutex_lock(philosopher->rightfork);
        printf("Philosopher %d picked up right fork\n", philosopher->philo_index);

        // Simulate eating
        printf("Philosopher %d is eating\n", philosopher->philo_index);
        usleep(1000000); // Simulate eating for 1 second

        // Release the forks
        pthread_mutex_unlock(philosopher->leftfork);
        printf("Philosopher %d released left fork\n", philosopher->philo_index);
        pthread_mutex_unlock(philosopher->rightfork);
        printf("Philosopher %d released right fork\n", philosopher->philo_index);

        // Simulate thinking
        printf("Philosopher %d is thinking\n", philosopher->philo_index);
        usleep(1000000); // Simulate thinking for 1 second
    }

    return NULL;
}

int main(int argc, char* argv[]) 
{
    int philo_number;
    int i;
    pthread_mutex_t *forks; 
    t_philo *philosophers;
    pthread_t *philosopher_threads;

    philo_number = atoi(argv[1]);
    forks = createfork(philo_number);
    philosophers = createphilo(philo_number, forks);
    philosopher_threads = createthread(philo_number, philosophers);

    // Allow philosophers to run indefinitely (not practical in a real scenario)
    while (1) {
        usleep(1000000); // Sleep for 1 second
    }

    // Join philosopher threads and clean up
    i = 0;
    while (i < NUM_PHILOSOPHERS) {
        pthread_join(philosopher_threads[i], NULL);
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    
    // Free memory
    free(forks);

    return 0;
}
