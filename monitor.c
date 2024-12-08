/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:18:31 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 15:23:59 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	increment_eat(t_philo *philo, t_general *general)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = philo->have_eaten;
	pthread_mutex_lock(philo->eat);
	while (i < philo->data->nbr_philos)
	{
		if (philo[i].have_eaten < tmp)
			tmp = philo[i].have_eaten;
		i++;
	}
	pthread_mutex_unlock(philo->eat);
	general->all_eat = tmp;
}

void	manage_dead(t_philo *philo)
{
	int		i;
	size_t	time_to_die;
	size_t	time;

	i = 0;
	time_to_die = philo->data->time_to_die;
	while (i < philo->data->nbr_philos)
	{
		time = get_current_time() - philo[i].start_time;
		pthread_mutex_lock(philo[i].eat);
		if (philo[i].last_eat - time > time_to_die)
		{
			pthread_mutex_lock(philo[i].dead);
			*philo[i].is_dead = 1;
			print_message("is died", &philo[i], time);
			pthread_mutex_unlock(philo[i].dead);
		}
		pthread_mutex_unlock(philo[i].eat);
		i++;
	}
}

int	check_eat(t_general *general, t_data *data)
{
	if (data->must_eat == -1)
		return (0);
	if (general->all_eat == data->must_eat)
	{
		pthread_mutex_lock(&general->dead);
		general->is_dead = 1;
		pthread_mutex_unlock(&general->dead);
	}
	return (1);
}

void	*monitor_func(void *arg)
{
	t_general	*general;
	t_data		*data;

	general = (t_general *) arg;
	data = general->philos->data;
	while (!dead_check(general->philos))
	{
		increment_eat(general->philos, general);
		check_eat(general, data);
		manage_dead(general->philos);
	}
	return (NULL);
}
