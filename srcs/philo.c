/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:32:06 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/25 16:15:56 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_msg(philo, FORK);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_msg(philo, FORK);
	}
	else if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_msg(philo, FORK);
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_msg(philo, FORK);
	}
}

void	unlock_fork(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	}
	else if (philo->id % 2)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	}
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	print_msg(philo, EAT);
	pthread_mutex_lock(&philo->data->death);
	philo->last_dinner = get_time();
	pthread_mutex_lock(&philo->data->meal);
	philo->total_meal++;
	pthread_mutex_unlock(&philo->data->meal);
	pthread_mutex_unlock(&philo->data->death);
	ft_usleep(philo->data->time_to_eat, philo->data);
	unlock_fork(philo);
}

void	*routine(void *philo)
{
	t_philo	*philosoph;

	philosoph = (t_philo *)philo;
	print_msg(philosoph, THINK);
	if (!(philosoph->id % 2))
		ft_usleep(philosoph->data->time_to_eat / 2, philosoph->data);
	while (!is_dead(philosoph->data) && !check_philo_full_ate(philosoph->data))
	{
		eat(philosoph);
		print_msg(philosoph, SLEEP);
		ft_usleep(philosoph->data->time_to_sleep, philosoph->data);
		print_msg(philosoph, THINK);
	}
	return (NULL);
}
