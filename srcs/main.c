/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:30:32 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/25 16:12:07 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (parsing(argc, argv, &data))
		return (EXIT_FAILURE);
	if (init_philo(&data) == ERROR)
	{
		free(data.philo);
		return (EXIT_FAILURE);
	}
	free_all(&data);
	return (EXIT_SUCCESS);
}
