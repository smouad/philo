/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:23:07 by msodor            #+#    #+#             */
/*   Updated: 2023/04/14 17:08:55 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_args(t_info *info, int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		info->number_of_philosophers = atoi(av[1]);
		info->time_to_die = atoi(av[2]);
		info->time_to_eat = atoi(av[3]);
		info->time_to_sleep = atoi(av[4]);
		if (ac == 6)
			info->number_of_times_each_philosopher_must_eat = atoi(av[5]);
	}
	else 
	{
		printf("Number of argumment incorrect! try again.");
		exit(0);
	}
}