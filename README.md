# PHILOSOPHERS

1. Philosophers
   - Explaining
     - Philosopher
     - Fork
     - Spaghetti
   - Problems
     - Deadlock
     - Data race
   - Usage

## Explaining
a scenario where a finite number of philosophers sit at a round table with a bowl of spaghetti in front of each. They alternate between thinking and eating. However, to eat, a philosopher needs both the fork to their left and the fork to their right.

The challenge arises in designing a solution that prevents deadlock (where no philosopher can proceed because they are all waiting for a fork held by another philosopher) and ensures that all philosophers can eventually eat without starving (i.e., waiting indefinitely to obtain both forks).

### philosopher 
Each philosopher is a thread

### fork
Each fork acts as a shared resource between two neighboring philosophers. However, the crucial point is that two philosophers cannot simultaneously use the same fork

### spaghetti
The spaghetti represents the process of eating. Each philosopher must acquire both forks (resources) to enter the critical section (eating) and consume the spaghetti

![philosphers](https://upload.wikimedia.org/wikipedia/commons/7/7b/An_illustration_of_the_dining_philosophers_problem.png)
## Usage

```
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

number_of_philosophers: The number of philosophers and also the number
of forks.

time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
