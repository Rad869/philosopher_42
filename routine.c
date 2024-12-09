/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:51:38 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/09 15:28:59 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	size_t	time;

	if (!dead_check(philo))
	{
		pthread_mutex_lock(philo->r_fork);
		time = get_current_time() - philo->start_time;
		print_message("has taken a fork", philo, time);
		pthread_mutex_lock(philo->l_fork);
		time = get_current_time() - philo->start_time;
		print_message("has taken a fork", philo, time);
		pthread_mutex_lock(philo->eat);
		philo->have_eaten += 1;
		philo->last_eat = get_current_time();
		pthread_mutex_unlock(philo->eat);
		print_message("is eating", philo, time);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

void	think(t_philo *philo)
{
	size_t	time;

	if (!dead_check(philo))
	{
		time = get_current_time() - philo->start_time;
		print_message("is thinking", philo, time);
	}
}

void	ft_sleep(t_philo *philo)
{
	size_t	time;

	if (!dead_check(philo))
	{
		time = get_current_time() - philo->start_time;
		print_message("is sleeping", philo, time);
		ft_usleep(philo->data->time_to_sleep);
	}
}

void	*routine(void *args)
{
	t_philo	*philo;
	size_t	tmp;

	philo = (t_philo *) args;
	if (philo->data->nbr_philos == 1)
	{
		tmp = get_current_time() - philo->start_time;
		print_message("has taken a fork", philo, tmp);
		ft_usleep(philo->data->time_to_die);
		tmp = get_current_time() - philo->start_time + 1;
		print_message("is died", philo, tmp);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(5);
	while (!dead_check(philo))
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}
