/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:00:27 by msodor            #+#    #+#             */
/*   Updated: 2023/05/17 12:40:17 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_finish(t_info *info)
{
	pthread_mutex_lock(&info->print);
	info->finish = 1;
	pthread_mutex_unlock(&info->print);
}

int	check_finish(t_info *info)
{
	int	i;

	while (info->finish == 0)
	{
		if (check_death(info))
		{
			lock_finish(info);
			return (1);
		}
		i = 0;
		check_full(info);
		while (i < info->num_philos)
		{
			if (!info->philo[i].full)
				break ;
			i++;
			if (i >= info->num_philos && info->meals_to_eat > 0)
			{
				lock_finish(info);
				return (1);
			}
		}
	}
	return (0);
}

void	free_join(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		pthread_join(info->philo[i].thread, NULL);
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print);
}
