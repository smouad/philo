#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_philo
{
	int	id;
} t_philo;
typedef struct s_info
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
} t_info;


void	get_args(t_info *info, int ac, char **av);

#endif