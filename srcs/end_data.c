/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:56:55 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/21 15:51:57 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void join_and_destroy_mutex(t_data *data)
{
	unsigned int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(data->philo[i].thread, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->meal);
	free(data->philo);
	free(data->forks);
} */