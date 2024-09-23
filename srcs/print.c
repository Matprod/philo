/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:33:25 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/20 16:46:09 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *str)
{
	long	time;

	if (is_dead(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print);
	time = get_time() - philo->data->start_time;
	if (!ft_strncmp(str, "fork", 4) && !is_dead(philo->data)
		&& !check_philo_full_ate(philo->data))
		printf("%ld %ld has taken a fork\n", time, philo->id);
	if (!ft_strncmp(str, "eat", 3) && !is_dead(philo->data)
		&& !check_philo_full_ate(philo->data))
		printf("%ld %ld is eating\n", time, philo->id);
	if (!ft_strncmp(str, "sleep", 5) && !is_dead(philo->data)
		&& !check_philo_full_ate(philo->data))
		printf("%ld %ld is sleeping\n", time, philo->id);
	if (!ft_strncmp(str, "think", 5) && !is_dead(philo->data)
		&& !check_philo_full_ate(philo->data))
		printf("%ld %ld is thinking\n", time, philo->id);
	if (!ft_strncmp(str, "dead", 4) && !is_dead(philo->data)
		&& !check_philo_full_ate(philo->data))
		printf("%ld %ld died\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

