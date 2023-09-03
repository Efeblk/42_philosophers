#include "philosophers.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX && sign == 1)
			return (INT_MAX);
		else if (result * -1 < INT_MIN && sign == -1)
			return (INT_MIN);
		++str;
	}
	return ((int)(result * sign));
}
