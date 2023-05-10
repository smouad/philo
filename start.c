/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:25:48 by msodor            #+#    #+#             */
/*   Updated: 2023/05/10 20:27:51 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
	// printf("%lld\n",philo->info->time_die);
	// printf("%lld\n",philo->info->time_eat);
	// printf("%lld\n",philo->info->time_sleep);
	while (philo->info->finish == 0)
	{
		print_msg(philo, "is thinking");
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_msg(philo, "has taken a fork");
		print_msg(philo, "is eating");
		my_sleep((long long)philo->info->time_eat);
		philo->last_meal = get_time();
		philo->meals += 1;
		// usleep(philo->info->time_eat);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		print_msg(philo, "is sleeping");
		// usleep(philo->info->time_sleep);
		my_sleep((long long)philo->info->time_sleep);
	}
	return (NULL);
}

void	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->print, 0) != 0)
	{
		printf("Mutex init failes");
		return ;
	}
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philos);
	while (i < info->num_philos)
	{
		if (pthread_mutex_init(&info->forks[i], 0) != 0)
		{
			printf("Mutex init failes");
			return ;
		}
		i++;
	}
}

void	death_checker(t_philo *philo)
{
	// while (!philo->info->finish)
	// {
		if (get_time() - philo->last_meal >= (long long)philo->info->time_die)
			philo->alive = 0;
	// }
}

void	check_full(t_philo *philo)
{
	while (!philo->full)
	{
		if (philo->meals < philo->info->meals_to_eat)
			philo->full = 1;
	}
}

void	create_philo(t_info *info)
{
	int	i;

	i = 0;
	long long creation_time = get_time();
	info->philo = malloc(sizeof(t_philo) * info->num_philos);
	while (i < info->num_philos)
	{
		info->philo[i].creation_time = creation_time;
		info->philo[i].id = i + 1;
		info->philo[i].meals = 0;
		info->philo[i].right_fork = i;
		info->philo[i].left_fork = (i + 1) % info->num_philos;
		info->philo[i].last_meal = get_time();
		info->philo[i].alive = 1;
		info->philo[i].info = info;
		pthread_create(&info->threads, NULL, cycle, &info->philo[i]);
		i++;
	}
}
