#include <limits.h>

static int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
    int sign = 1;
    long long result = 0;

    while (ft_isspace(*str))
        ++str;

    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        ++str;
    }

    while (ft_isdigit(*str)) {
        result = result * 10 + (*str - '0');

        if (result > INT_MAX && sign == 1)
            return INT_MAX;
        else if (result * -1 < INT_MIN && sign == -1)
            return INT_MIN;

        ++str;
    }

    return (int)(result * sign);
}