/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:18 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/03 21:50:20 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	rules = NULL;
	rules = createrules(rules, argv);
	forks = createfork(rules->philo_number);
	philosophers = createphilo(rules->philo_number, forks, rules);
	philosopher_threads = createthread(rules->philo_number, philosophers);
	if (main_check(philosophers, rules))
	{
		detach_threads(rules, philosopher_threads, forks);
		fre(rules, philosophers, forks, philosopher_threads);
		return (1);
	}
	join_threads(rules, philosopher_threads, forks);
	fre(rules, philosophers, forks, philosopher_threads);
	return (0);
}
