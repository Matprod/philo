/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:30:32 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/22 11:51:20 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (parsing(argc, argv, &data))
		return (EXIT_FAILURE);
	free_all(&data);
	return (EXIT_SUCCESS);
}
