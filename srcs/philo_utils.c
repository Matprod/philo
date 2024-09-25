/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:03:15 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/25 16:11:13 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_last_dinner(t_philo *philo)
{
	long long	ret;

	pthread_mutex_lock(&philo->data->death);
	ret = philo->last_dinner;
	pthread_mutex_unlock(&philo->data->death);
	return (ret);
}

bool	get_full_ate(t_data *data)
{
	int				i;
	unsigned int	count;

	i = -1;
	count = 0;
	if (data->nb_of_dinner == -1)
		return (false);
	pthread_mutex_lock(&data->meal);
	while ((unsigned int)++i < data->nb_philo)
	{
		if ((int)data->philo[i].total_meal >= data->nb_of_dinner)
			count ++;
	}
	pthread_mutex_unlock(&data->meal);
	return (count == data->nb_philo);
}

bool	is_dead(t_data *data)
{
	bool	ret;

	pthread_mutex_lock(&data->death);
	ret = data->is_dead;
	pthread_mutex_unlock(&data->death);
	return (ret);
}

bool	check_philo_full_ate(t_data *data)
{
	int				i;
	unsigned int	philos_fully_fed;

	philos_fully_fed = 0;
	if (data->nb_of_dinner == -1)
		return (FALSE);
	pthread_mutex_lock(&data->meal);
	i = 0;
	while (i < (int)data->nb_philo)
	{
		if (data->philo[i].total_meal >= data->nb_of_dinner)
			philos_fully_fed++;
		i++;
	}
	pthread_mutex_unlock(&data->meal);
	if (philos_fully_fed == data->nb_philo)
		return (TRUE);
	return (FALSE);
}
