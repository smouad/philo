/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:42:16 by msodor            #+#    #+#             */
/*   Updated: 2023/05/07 17:09:09 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_info	t_info;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	t_info			*info;
}	t_philo;

typedef struct s_info
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals_to_eat;
	pthread_mutex_t	*forks;
	pthread_t		threads;
	t_philo			philo[200];
}	t_info;

int		check_input(t_info *info, int ac, char **av);
void	*cicle(void *arg);
void	create_philo(t_info *info);
void	init_mutex(t_info *info);
int		ft_atoi(const char *str);

#endif