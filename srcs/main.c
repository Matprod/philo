/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:30:32 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/26 14:11:10 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (parsing(argc, argv, &data) == ERROR)
		return (EXIT_FAILURE);
	if (init_philo(&data) == ERROR)
	{
		free(data.philo);
		return (EXIT_FAILURE);
	}
	free_all(&data);
	return (EXIT_SUCCESS);
}
