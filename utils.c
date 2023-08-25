#include "philosophers.h"

long get_current_time_ms() 
{
    struct timeval tv;
    gettimeofday(&tv, (void *)0);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

long time_diff(long start, long end)
{
    return(end - start);
}