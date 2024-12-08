/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:42:29 by rrabeari          #+#    #+#             */
/*   Updated: 2024/12/08 15:15:15 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char *arg)
{
	if (!arg)
		return (0);
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (0);
		arg++;
	}
	return (1);
}

static int	check_input(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	print_error(char *err)
{
	write(2, err, ft_strlen(err));
	return (0);
}

int	check_error(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (print_error("Error of argument\n"));
	if (!check_input(argc, argv))
		return (print_error("Error of argument\n"));
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0)
			return (print_error("Input argument zero\n"));
		i++;
	}
	return (1);
}
