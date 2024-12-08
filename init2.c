/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:20:57 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 15:29:46 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lanch_loop(t_general *general, t_data *data, t_philo *philo)
{
	pthread_t	monitor;
	int			i;
	size_t		time;

	i = 0;
	time = get_current_time() - philo->start_time;
	if (data->nbr_philos == 1)
	{
		print_message("has taken a fork",philo, time);
		ft_usleep(data->time_to_die);
		print_message("is died", philo, time);
		return ;
	}
	pthread_create(&monitor, NULL, &monitor_func, (void *) general);
	while (i < data->nbr_philos)
	{
		pthread_create(&philo[i].thread, NULL, &routine, (void *) &philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
