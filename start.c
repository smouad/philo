#include "philo.h"

void	*create_philo(void* i)
{
	printf("philo : %d\n", (int)i);
	return(NULL);
}


int main(int ac, char **av)
{
	t_info		info;
	pthread_t	*thread;
	size_t	i = 1;

	get_args(&info, ac, av);
	thread = malloc(sizeof(t_philo) * info.number_of_philosophers);
	while ((int) i <= info.number_of_philosophers)
	{
		pthread_create(&thread[i], NULL,  &create_philo, (void *)i);
		usleep(10);
		i++;
	}
	i = 0;
	while ((int) i <= info.number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
