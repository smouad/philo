#include "philo.h"

void	*p_life(t_info *info)
{
	
}
void	creat_philo(t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].meals = 0;
		info->philo[i].right_fork = i; 
		info->philo[i].left_fork = (i + 1) % info->num_philos;
		pthread_create(&info->philo[i].thread, NULL, p_life, &info->philo[i])
	}
}