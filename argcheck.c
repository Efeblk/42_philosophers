int argcheck(char *argv[])
{
    number_of_philo(atoi(argv[1]));
    return (0);
}

//number_of_philosophers time_to_die time_to_eat time_to_sleep
//[number_of_times_each_philosopher_must_eat]

int number_of_philo(int philo_number)
{
    if (philo_number < 1)
        return (1);
    return(0);
}