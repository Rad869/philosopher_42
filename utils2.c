/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:21:06 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 15:20:59 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->dead);
	if (*philo->is_dead == 1)
		return (pthread_mutex_unlock(philo->dead), 1);
	return (pthread_mutex_unlock(philo->dead), 0);
}

void	ft_usleep(size_t time)
{
	usleep(time * 1000);
}
