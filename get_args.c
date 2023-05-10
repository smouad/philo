/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:25:07 by msodor            #+#    #+#             */
/*   Updated: 2023/05/10 15:28:32 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(t_info *info, int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		info->num_philos = ft_atoi(av[1]);
		info->time_die = ft_atoi(av[2]);
		info->time_eat = ft_atoi(av[3]);
		info->time_sleep = ft_atoi(av[4]);
		info->finish = 0;
		info->meals_to_eat = -1;
		if (ac == 6)
			info->meals_to_eat = ft_atoi(av[5]);
	}
	else
	{
		printf("Error: Number of argumment incorrect.\n");
		return (1);
	}
	if (info->num_philos < 0 || info->time_eat < 0 \
	|| info->time_die < 0 || info->time_sleep < 0 || info->meals_to_eat < -1)
	{
		printf("Error: All arguments must be positive integers.\n");
		return (1);
	}
	return (0);
}
