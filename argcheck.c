#include "philosophers.h"

static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

static int isalldigit(char *arg)
{
    while (*arg) 
    {
        if (!ft_isdigit(*arg))
            return 0;
        arg++;
    }
    return 1;
}

static int number_of_philo(int philo_number)
{
    if (philo_number < 1)
        return 1;
    return 0;
}

int argcheck(char *argv[])
{
    argv++;
    while (*argv)
    {
        if (!isalldigit(*argv))
            return (1);
        if (number_of_philo(ft_atoi(*argv)))
            return (1);
        argv++;
    }
    return 0;
}
