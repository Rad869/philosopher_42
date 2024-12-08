/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:58:13 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 10:46:36 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int argc, char *argv[], pthread_mutex_t *fork)
{
	data->nbr_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	data->forks = fork;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
}

void	init_philo(t_philo *philos, t_general *general, t_data *data)
{
	int	i;
	int	nbr_philos;

	i = 0;
	nbr_philos = data->nbr_philos;
	while (i < nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].is_dead = &general->is_dead;
		philos[i].have_eaten = 0;
		philos[i].eat = &general->eat;
		philos[i].l_fork = &data->forks[i];
		philos[i].start_time = get_current_time();
		philos[i].last_eat = get_current_time();
		philos[i].write = &general->write;
		philos[i].dead = &general->dead;
		if (i == 0)
			philos[i].r_fork = &data->forks[nbr_philos - 1];
		else
			philos[i].r_fork = &data->forks[i - 1];
	}
}

void	init_general(t_general *general, t_philo *philos)
{
	general->is_dead = 0;
	general->all_eat = 0;
	general->philos = philos;
	pthread_mutex_init(&general->eat, NULL);
	pthread_mutex_init(&general->dead, NULL);
	pthread_mutex_init(&general->write, NULL);
}

void	init_fork(pthread_mutex_t *forks, int nbr_philos)
{
	int	i;

	i = 0;
	while (i < nbr_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	destroy_data(t_general *general, pthread_mutex_t *forks, int nbr)
{
	int				i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&general->eat);
	pthread_mutex_destroy(&general->dead);
	pthread_mutex_destroy(&general->write);
}
