/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:59:37 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 15:22:36 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# define PHILO_MAX 200

typedef struct s_data
{
	int				nbr_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				*is_dead;
	int				have_eaten;
	t_data			*data;
	size_t			start_time;
	size_t			last_eat;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*write;
}	t_philo;

typedef struct s_general
{
	int				is_dead;
	int				all_eat;
	t_philo			*philos;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
	pthread_mutex_t	write;
}	t_general;

// -----------Initialisation of value of the struct-----------
void	init_fork(pthread_mutex_t *forks, int nbr_philos);
void	init_general(t_general *general, t_philo *philos);
void	init_philo(t_philo *philos, t_general *general, t_data *data);
void	init_data(t_data *data, int argc, char *argv[], pthread_mutex_t *fork);

//-----------Destructor--------------------------------------
void	destroy_data(t_general *general, pthread_mutex_t *forks, int nbr);

//-----------Functions utils----------------------------------
int		ft_atoi(const char *arg);
int		check_error(int argc, char *argv[]);
size_t	ft_strlen(const char *args);
size_t	get_current_time(void);
int		dead_check(t_philo *philo);
void	ft_usleep(size_t time);
void	print_message(char *mes, t_philo *philo, size_t time);
void	*monitor_func(void *arg);
void	*routine(void *args);
void	lanch_loop(t_general *general, t_data *data, t_philo *philo);

//-----------Destroy all mutex--------------------------------

#endif
