/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:56:52 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 15:19:26 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *args)
{
	size_t	count;

	count = 0;
	while (*args)
	{
		args++;
		count++;
	}
	return (count);
}

int	ft_atoi(const char *arg)
{
	int	value;

	value = 0;
	if (!arg)
		return (0);
	while (*arg)
	{
		value = value * 10;
		value += *arg - '0';
		arg++;
	}
	return (value);
}

void	print_message(char *mes, t_philo *philo, size_t time)
{
	pthread_mutex_lock(philo->dead);
	if (!*philo->is_dead)
	{
		pthread_mutex_lock(philo->write);
		printf("%zu %d %s\n", time, philo->id, mes);
		pthread_mutex_unlock(philo->write);
	}
	pthread_mutex_unlock(philo->dead);
}
