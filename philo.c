/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:25:29 by msodor            #+#    #+#             */
/*   Updated: 2023/05/07 15:44:55 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (check_input(info, ac, av))
		return (0);
	printf("%d\n", info->num_philos);
	printf("%d\n", info->time_die);
	printf("%d\n", info->time_eat);
	printf("%d\n", info->time_sleep);
	printf("%d\n", info->meals_to_eat);
	create_philo(info);
	return (0);
}
