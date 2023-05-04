/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:25:48 by msodor            #+#    #+#             */
/*   Updated: 2023/05/04 17:27:52 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cicle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("philo id: %d", philo->id);
	return (NULL);
}

// void	init_mutex(t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	while (i < info->num_philos)
// 	{
// 		pthread_mutex_init(&info->forks[i], 0);
// 		if (pthread_mutex_init(&info->forks[i], 0) != 0)
// 		{
// 			printf("Mutex init failes");
// 			return ;
// 		}
// 		i++;
// 	}
// }

void	create_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].meals = 0;
		info->philo[i].right_fork = i;
		info->philo[i].left_fork = (i + 1) % info->num_philos;
		pthread_create(&info->philo[i].thread, NULL, cicle, &info->philo[i]);
	}
}
