/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:42:16 by msodor            #+#    #+#             */
/*   Updated: 2023/05/10 20:12:21 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_info	t_info;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				left_fork;
	int				right_fork;
	int				full;
	int				alive;
	long long		last_meal;
	long long		creation_time;
	t_info			*info;
}	t_philo;

typedef struct s_info
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals_to_eat;
	int				finish;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_t		threads;
	t_philo			*philo;
}	t_info;

int			check_input(t_info *info, int ac, char **av);
void		*cycle(void *arg);
void		create_philo(t_info *info);
void		init_mutex(t_info *info);
long long	get_time(void);
void		print_msg(t_philo *philo, char *msg);
void		my_sleep(long long sleep_time);
void		death_checker(t_philo *philo);
int			ft_atoi(const char *str);

#endif