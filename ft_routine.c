/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:25:48 by msodor            #+#    #+#             */
/*   Updated: 2023/10/28 13:19:49 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(&philo->info->print);
		if (philo->info->finish == 1)
			return (pthread_mutex_unlock(&philo->info->print), NULL);
		pthread_mutex_unlock(&philo->info->print);
		print_msg(philo, "is thinking");
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_msg(philo, "has taken a fork");
    print_msg(philo, "is eating");
    my_sleep(philo->info->time_eat, philo);
    pthread_mutex_lock(&philo->info->print);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->info->print);
    pthread_mutex_lock(&philo->info->print);
    philo->meals += 1;
    pthread_mutex_unlock(&philo->info->print);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		print_msg(philo, "is sleeping");
		my_sleep(philo->info->time_sleep, philo);
	}
	return (NULL);
}

void	kill_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		pthread_mutex_lock(&info->print);
		info->philo[i].alive = 0;
		pthread_mutex_unlock(&info->print);
		i++;
	}
}

int	check_death(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		pthread_mutex_lock(&info->print);
		if (get_time() - info->philo[i].last_meal > info->time_die)
		{
			pthread_mutex_unlock(&info->print);
			kill_all(info);
			pthread_mutex_lock(&info->print);
			printf("%lld %d %s\n", get_time() - info->philo->creation_time, \
			info->philo->id, "died");
			pthread_mutex_unlock(&info->print);
			if (info->num_philos == 1)
				pthread_mutex_unlock(&info->forks[0]);
			return (1);
		}
		pthread_mutex_unlock(&info->print);
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
		pthread_mutex_lock(&info->print);
		if (info->philo[i].meals >= info->meals_to_eat)
			info->philo[i].full = 1;
		pthread_mutex_unlock(&info->print);
		i++;
	}
}
