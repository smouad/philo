/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:25:48 by msodor            #+#    #+#             */
/*   Updated: 2023/05/13 21:56:59 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (philo->info->finish == 0)
	{
		print_msg(philo, "is thinking");
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_msg(philo, "has taken a fork");
		print_msg(philo, "is eating");
		my_sleep(philo->info->time_eat);
		philo->last_meal = get_time();
		philo->meals += 1;
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		print_msg(philo, "is sleeping");
		my_sleep(philo->info->time_sleep);
	}
	return (NULL);
}

int	check_death(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (get_time() - info->philo[i].last_meal >= info->time_die)
		{
			print_msg(info->philo, "died");
			i = 0;
			while (i < info->num_philos)
			{
				info->philo[i].alive = 0;
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_full(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (info->philo[i].meals >= info->meals_to_eat)
			info->philo[i].full = 1;
		i++;
	}
}

int	check_finish(t_info *info)
{
	int	i;

	while (info->finish == 0)
	{
		if (check_death(info))
		{
			info->finish = 1;
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
				info->finish = 1;
				return (1);
			}
		}
	}
	return (0);
}
