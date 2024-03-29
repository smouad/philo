/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:42:16 by msodor            #+#    #+#             */
/*   Updated: 2023/10/28 13:18:10 by msodor           ###   ########.fr       */
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
	pthread_t		thread;
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
	pthread_mutex_t	lock;
	t_philo			*philo;
}	t_info;

/* --- Init --- */
void		get_input(t_info *info, int ac, char **av);
int			check_input(t_info *info, int ac);
void		create_philo(t_info *info);
void		init_mutex(t_info *info);

/* --- Print --- */
void		print_msg(t_philo *philo, char *msg);
long long	get_time(void);
void		my_sleep(int sleep_time, t_philo *philo);

/* --- Actions --- */
void		*cycle(void *arg);
int			check_death(t_info *info);
int			check_finish(t_info *info);
int			ft_atoi(const char *str);
void		free_join(t_info *info);
void		check_full(t_info *info);

#endif