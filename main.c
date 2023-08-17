#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

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
    pthread_mutex_t *forks = createfork(NUM_PHILOSOPHERS);
    t_philo philosophers[NUM_PHILOSOPHERS];
    pthread_t philosopher_threads[NUM_PHILOSOPHERS];

    int i = 0;

    // Initialize philosophers using while loop
    while (i < NUM_PHILOSOPHERS) {
        philosophers[i].philo_index = i;
        philosophers[i].leftfork = &forks[i];
        philosophers[i].rightfork = &forks[(i + 1) % NUM_PHILOSOPHERS];
        pthread_create(&philosopher_threads[i], NULL, philosopher_thread, &philosophers[i]);
        i++;
    }

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
