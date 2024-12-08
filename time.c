/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:02:36 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/07 12:07:57 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	val;

	if (gettimeofday(&val, NULL) == -1)
		write(2, "Error of gettimeofday\n", 22);
	return (val.tv_sec * 1000 + val.tv_usec / 1000);
}
