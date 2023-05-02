/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:23:07 by msodor            #+#    #+#             */
/*   Updated: 2023/05/02 11:22:58 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_input(t_info *info, int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		info->num_philos = ft_atoi(av[1]);
		info->time_die = ft_atoi(av[2]);
		info->time_eat = ft_atoi(av[3]);
		info->time_sleep = ft_atoi(av[4]);
		info->meals_to_eat = -1;
		if (ac == 6)
			info->meals_to_eat = ft_atoi(av[5]);
	}
	else if (info->num_philos < 0 || info->time_eat < 0
	|| info->time_die < 0 || info->time_sleep < 0 || info->meals_to_eat < 0)
	{
		printf("Error: All arguments must be positive integers.\n");
		return;
	}
	else
	{
		printf("Error: Number of argumment incorrect.");
		return;
	}
}
