/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:24:55 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/23 15:24:08 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_negativ(long number)
{
	if (number < 0)
		return (TRUE);
	else
		return (FALSE);
}

static bool	check_data(t_data *data)
{
	if (is_negativ(data->time_to_die))
		return (printf("%s2n",NEG_ARG), ERROR);
	if (is_negativ(data->time_to_eat))
		return (printf("%s\n",NEG_ARG), ERROR);
	if (is_negativ(data->time_to_sleep))
		return (printf("%s\n",NEG_ARG), ERROR);
	if (data->nb_of_dinner == -1)
		return (SUCCESS);
	else if (is_negativ(data->nb_of_dinner))
		return (printf("%s\n",NEG_ARG), ERROR);
	return (SUCCESS);
}

static bool if_one_philo(char **av)
{
	if (ft_atol(av[1]) == 1)
	{
		printf("0 1 is thinking\n");
		printf("0 1 has taken a fork\n");
		usleep(ft_atol(av[2]) * 1000);
		printf("%ld 1 died\n", ft_atol(av[2]));
		return (TRUE);
	}
	return (FALSE);
}

bool	parsing(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (TRUE);
	if (if_one_philo(argv) == ERROR)
		return (TRUE);
	if (init_mutex(argc, argv, data) == ERROR)
		return (TRUE);
	get_info_ms(data);
	if (check_data(data) == ERROR)
	{
		free(data->forks);
		return (TRUE);
	}
	if (init_philo(data) == ERROR)
	{
		free(data->philo);
		return (TRUE);
	}
	return (FALSE);
}
