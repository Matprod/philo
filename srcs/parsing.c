/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:24:55 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/25 16:13:06 by Matprod          ###   ########.fr       */
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
		return (printf("%s2n", NEG_ARG), ERROR);
	if (is_negativ(data->time_to_eat))
		return (printf("%s\n", NEG_ARG), ERROR);
	if (is_negativ(data->time_to_sleep))
		return (printf("%s\n", NEG_ARG), ERROR);
	if (data->nb_of_dinner == -1)
		return (SUCCESS);
	else if (is_negativ(data->nb_of_dinner))
		return (printf("%s\n", NEG_ARG), ERROR);
	return (SUCCESS);
}

static bool	if_one_philo(char **av)
{
	if (ft_atol(av[1]) == 1)
	{
		printf("0 1 is thinking\n");
		printf("0 1 has taken a fork\n");
		usleep(ft_atol(av[2]) * 1000);
		printf("%ld 1 died\n", ft_atol(av[2]));
		return (EXIT_FAILURE);
	}
	return (SUCCESS);
}

bool	parsing(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	if (if_one_philo(argv) == ERROR)
		return (EXIT_FAILURE);
	if (init_data_and_mutex(argc, argv, data) == ERROR)
		return (EXIT_FAILURE);
	if (check_data(data) == ERROR)
	{
		free(data->forks);
		return (EXIT_FAILURE);
	}
	return (SUCCESS);
}
