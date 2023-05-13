/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:27:55 by msodor            #+#    #+#             */
/*   Updated: 2023/05/13 10:51:41 by msodor           ###   ########.fr       */
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

void	my_sleep(int sleep_time)
{
	long long	current;

	current = get_time();
	while (1)
	{
		if (get_time() - current >= sleep_time)
			break ;
		usleep(100);
	}
}
