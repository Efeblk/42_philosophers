/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:24 by ibalik            #+#    #+#             */
/*   Updated: 2023/09/04 05:25:56 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isalldigit(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

int	number_of_philo(int philo_number)
{
	if (philo_number < 1)
		return (1);
	return (0);
}

int	argcheck(char *argv[])
{
	long	check;
	int		i;

	i = 1;
	check = 0;
	if (argv[5] && *argv[5] == '0')
		return (1);
	if (number_of_philo(ft_atoi(argv[i])))
		return (1);
	while (argv[i])
	{
		if (!isalldigit(argv[i]))
			return (1);
		i++;
	}
	i = 1;
	while (argv[i])
	{
		check = ft_atoi(argv[i]);
		if (check > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}
