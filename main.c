/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:09:14 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 15:18:23 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_general		general;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	t_data			data;

	if (!check_error(argc, argv))
		return (1);
	init_general(&general, philos);
	init_data(&data, argc, argv, forks);
	init_fork(forks, data.nbr_philos);
	lanch_loop(&general, &data, philos);
	destroy_data(&general, forks, data.nbr_philos);
}
