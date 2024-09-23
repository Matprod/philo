/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/21 14:09:01 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while (*str && (*str == ' ' || *str == '\t'
			|| *str == '\n' || *str == '\r'
			|| *str == '\v' || *str == '\f'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

void	get_info_ms(t_data *data)
{
	printf("Number of philo : %ld\n", data->nb_philo);
	printf("Time to die : %ld\n", data->time_to_die);
	printf("Time to eat : %ld\n", data->time_to_eat);
	printf("Time to sleep : %ld\n", data->time_to_sleep);
	printf("Number of dinner : %ld\n", data->nb_of_dinner);
}

void	get_info_sec(t_data *data)
{
	printf("Number of philo : %ld\n", data->nb_philo);
	printf("Time to die : %ld\n", data->time_to_die * 1000);
	printf("Time to eat : %ld\n", data->time_to_eat * 1000);
	printf("Time to sleep : %ld\n", data->time_to_sleep * 1000);
	printf("Number of dinner : %ld\n", data->nb_of_dinner);
}