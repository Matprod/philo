/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/25 16:10:28 by Matprod          ###   ########.fr       */
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

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while ((unsigned int)++i < data->nb_philo)
		pthread_join(data->philo[i].thread, NULL);
	while ((unsigned int)++i < data->nb_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->meal);
	free(data->philo);
	free(data->forks);
}
