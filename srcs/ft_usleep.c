/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:39:13 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/25 16:10:22 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(long usec, t_data *data)
{
	long long	start;
	long long	elapsed;
	long long	rem;

	start = get_time();
	elapsed = 0;
	while (elapsed < usec && !is_dead(data) && !check_philo_full_ate(data))
	{
		elapsed = get_time() - start;
		rem = usec - elapsed;
		if (rem > 2000)
			usleep(rem / 2);
		else if (rem > 1000)
			usleep(500);
		else
			usleep(100);
	}
}

void	ft_usleep_no_check(long usec)
{
	long long	time;

	time = get_time();
	while (get_time() - time < usec)
		usleep(1000);
}
