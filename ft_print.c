/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:27:55 by msodor            #+#    #+#             */
/*   Updated: 2023/05/17 16:40:39 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(t_philo *philo, char *ms)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->finish == 0)
		printf("%lld %d %s\n", get_time() - philo->creation_time, philo->id, ms);
	pthread_mutex_unlock(&philo->info->print);
}

void	my_sleep(int sleep_time, t_philo *philo)
{
	long long	current;

	current = get_time();
	while (1)
	{
		pthread_mutex_lock(&philo->info->print);
		if (get_time() - current >= sleep_time || !philo->alive)
		{
			pthread_mutex_unlock(&philo->info->print);
			break ;
		}
		pthread_mutex_unlock(&philo->info->print);
		usleep(300);
	}
}
