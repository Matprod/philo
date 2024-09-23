/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:38 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/23 17:02:04 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->death);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->death);
	pthread_mutex_lock(&data->print);
	printf("%ld %ld died\n", get_time()
		- data->start_time, data->philo[i].id);
	pthread_mutex_unlock(&data->print);
}

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

int	is_end_simulation(t_data *data)
{
	int	i;

	while (!data->is_dead)
	{
		i = -1;
		while ((unsigned int)++i < data->nb_philo)
		{
			if (get_time() - get_last_dinner(&data->philo[i])
				>= data->time_to_die)
			{
				ft_death(data, i);
				break ;
			}
			if (get_full_ate(data))
				break ;
			ft_usleep(1, data);
		}
		if (get_full_ate(data))
			break ;
	}
	return (1);
}

bool	init_mutex(int argc, char **argv, t_data *data)
{
	int	i;

	data->is_dead = FALSE;
	data->nb_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->start_time = get_time();
	if (argc == 6)
		data->nb_of_dinner = ft_atol(argv[5]);
	else
		data->nb_of_dinner = -1;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philo);
	if (!data->forks)
		return (TRUE);
	i = -1;
	while ((unsigned int)++i < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->meal, NULL);
	return (FALSE);
}

bool	init_philo(t_data *data)
{
	int	i;

	data->philo = (t_philo *)malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philo)
		return (TRUE);
	i = -1;
	while ((unsigned int)++i < data->nb_philo)
	{
		data->philo[i].total_meal = 0;
		data->philo[i].id = i + 1;
		data->philo[i].last_dinner = get_time();
		data->philo[i].data = data;
		data->philo[i].left_fork = i;
		if ((unsigned int)i == data->nb_philo - 1)
			data->philo[i].right_fork = 0;
		else
			data->philo[i].right_fork = i + 1;
		if (pthread_create(&data->philo[i].thread, NULL, \
			&routine, &(data->philo[i])))
			return (TRUE);
	}
	is_end_simulation(data);
	return (FALSE);
}
