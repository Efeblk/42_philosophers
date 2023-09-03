#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_rules			*rules;
	pthread_mutex_t	*forks;
	t_philo			*philosophers;
	pthread_t		*philosopher_threads;

	if (argc < 5)
		return (1);
	if (argcheck(argv))
		return (1);
	rules = createrules(rules, argv);
	forks = createfork(rules->philo_number);
	philosophers = createphilo(rules->philo_number, forks, rules);
	philosopher_threads = createthread(rules->philo_number, philosophers);
	if (main_check(philosophers, rules))
	{
		freeer(rules, philosophers, forks, philosopher_threads);
		detach_threads(rules, philosopher_threads, forks);
		return (1);
	}
	join_threads(rules, philosopher_threads, forks);
	freeer(rules, philosophers, forks, philosopher_threads);
	return (0);
}
