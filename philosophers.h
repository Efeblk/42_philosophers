/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:32 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/03 21:50:33 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define FORK "%ld %d has taken a fork\n"
# define DEAD "%ld %d died\n"
# define EATING "%ld %d is eating\n"
# define SLEEPING "%ld %d is sleeping\n"
# define THINKING "%ld %d is thinking\n"

typedef struct s_rules
{
	long	start_time;
	int		philo_number;
	int		death_time;
	int		eating_time;
	int		sleeping_time;
	int		nbreat;
	int		b_eat;
}t_rules;

typedef struct s_philo
{
	int				philo_index;
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
	int				meal;
	int				is_dead;
	long			last_eat_time;
	t_rules			*rules;
}t_philo;

void			fork_lock(t_philo *philosopher);
void			fork_unlock(t_philo *philosopher);
void			philo_eat(t_philo *philosopher);
void			philo_sleep(t_philo *philosopher);
void			*philosopher_thread(void *arg);

pthread_mutex_t	*createfork(int fork_number);
pthread_t		*createthread(int thread_number, t_philo *philosophers);
t_philo			*createphilo(int philo_number, pthread_mutex_t *f, t_rules *r);
t_rules			*createrules(t_rules *rules, char *argv[]);

int				isalldigit(char *arg);
int				number_of_philo(int philo_number);
int				argcheck(char *argv[]);

int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

int				check_dying(long remaining_time, t_philo *philosopher);
void			ft_sleep(long time, t_philo *philosopher);
long			get_current_time_ms(void);

int				main_check(t_philo *philosophers, t_rules *rules);
void			join_threads(t_rules *r, pthread_t *t, pthread_mutex_t *f);
void			detach_threads(t_rules *r, pthread_t *t, pthread_mutex_t *f);
void			fre(t_rules *r, t_philo *p, pthread_mutex_t *f, pthread_t *t);
#endif 