# PHILOSOPHERS

1. Philosophers
   - Explaining
     - Philosopher
     - Fork
     - Spaghetti
   - Problems
     - Deadlock
     - Data race
   - Mutex
   - Usage

## Explaining
a scenario where a finite number of *philosophers* sit at a round table with a bowl of *spaghetti* in front of each. They alternate between **thinking** and **eating**. However, to eat, a *philosopher* needs both the *fork* to their left and the *fork* to their right.

The challenge arises in designing a solution that prevents deadlock (where no philosopher can proceed because they are all waiting for a fork held by another philosopher) and ensures that all philosophers can eventually eat without starving (i.e., waiting indefinitely to obtain both forks).

### philosopher 
Each *philosopher* is a **thread**

### fork
Each *fork* acts as a shared resource between two neighboring *philosophers*. However, the crucial point is that two *philosophers* cannot simultaneously use the same *fork*

### spaghetti
The spaghetti represents the process of eating. Each *philosopher* must acquire both *forks* (resources) to enter the critical section (eating) and consume the spaghetti

![philosphers](https://upload.wikimedia.org/wikipedia/commons/7/7b/An_illustration_of_the_dining_philosophers_problem.png)

## Problems

### Deadlock

deadlock occurs when each *philosopher* holds one *fork* and is waiting for the neighboring *philosopher* to release the other *fork*.

Each *philosopher* picks up the *fork* on their left.
Each *philosopher* waits indefinitely for the *fork* on their right to become available.

As a result, all *philosophers* are stuck in a state where they cannot proceed because they are each waiting for a resource held by another *philosopher*. This situation creates a **deadlock**, as no *philosopher* can continue eating, and they remain in a state of indefinite waiting.

**Deadlock** in the *philosopher's* problem is a consequence of improper resource allocation and synchronization. If the *philosopher*s are not managed properly to ensure that all required resources (*forks*) are available when needed, **deadlock** can occur, leading to a situation where none of the *philosophers* can progress further with their tasks.

![Deadlock](https://github.com/Efeblk/philosophers/assets/108200358/8e9377c5-b83b-44b1-97b3-bb988d3dc66a)

## Usage

```
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

number_of_philosophers: The number of *philosophers* and also the number
of *forks*.

time_to_die (in milliseconds): If a *philosopher* didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

time_to_eat (in milliseconds): The time it takes for a *philosopher* to eat.
During that time, they will need to hold two *forks*.

time_to_sleep (in milliseconds): The time a *philosopher* will spend sleeping.

number_of_times_each_philosopher_must_eat (optional argument): If all
*philosophers* have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
*philosopher* dies.

