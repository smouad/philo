/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:25:29 by msodor            #+#    #+#             */
/*   Updated: 2023/05/10 20:19:50 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	int		i;

	i = 0;
	if (check_input(&info, ac, av))
		return (0);
	init_mutex(&info);
	create_philo(&info);
	while (info.finish == 0)
	{
		i = 0;
		death_checker(&info.philo[i]);
		if (info.philo[i].alive == 0)
		{
			printf("MAT LAH YRHMO\n");
			info.finish = 1;
		}
		i++;
	}
	return (0);
}
