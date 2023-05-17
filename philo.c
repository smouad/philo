/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:25:29 by msodor            #+#    #+#             */
/*   Updated: 2023/05/17 12:33:16 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	*info;
	int		i;

	i = 0;
	info = malloc(sizeof(t_info));
	get_input(info, ac, av);
	if (check_input(info, ac))
		return (1);
	init_mutex(info);
	create_philo(info);
	if (check_finish(info))
	{
		free_join(info);
		return (free(info->philo), free(info), 1);
	}
	return (free(info->philo), free(info), 0);
}
