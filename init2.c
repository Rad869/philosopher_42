/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:20:57 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/09 14:59:48 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_data *data, t_philo *philos, t_general *general)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
	i = 0;
	while (!dead_check(philos) && data->nbr_philos != 1)
		monitor_func((void *) general);
	while (i < data->nbr_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
