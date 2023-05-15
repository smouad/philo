/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:25:29 by msodor            #+#    #+#             */
/*   Updated: 2023/05/15 15:48:18 by msodor           ###   ########.fr       */
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
		while (1);	
		return (1);
	}
	return (0);
}
