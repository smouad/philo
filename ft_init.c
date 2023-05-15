/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:47:28 by msodor            #+#    #+#             */
/*   Updated: 2023/05/15 14:52:34 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

void	get_input(t_info *info, int ac, char **av)
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
		write(2, "Error: Number of argumment incorrect.\n", 38);
}

int	check_input(t_info *info, int ac)
{
	if ((ac == 6 && info->meals_to_eat <= 0) \
	|| info->num_philos <= 0 || info->time_eat < 60 \
	|| info->time_die < 60 || info->time_sleep < 60)
	{
		write(2, "Error: Wrong input.\n", 20);
		return (1);
	}
	return (0);
}

void	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->print, 0);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philos);
	while (i < info->num_philos)
		pthread_mutex_init(&info->forks[i++], 0);
}

void	create_philo(t_info *info)
{
	int			i;
	long long	creation_time;

	i = 0;
	creation_time = get_time();
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
		pthread_create(&info->philo[i].thread, NULL, cycle, &info->philo[i]);
		i++;
	}
}
