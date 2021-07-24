/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:08:33 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/23 19:25:29 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	long	time;

	philo = (t_philo *)arg;
	info = philo->info;
	while (info->alive)
	{
		time = ft_get_time();
		if (time - philo->last_eat > info->time_die)
		{
			ft_printf(info, time, philo->index, "died");
			info->alive = 0;
			philo->alive = 0;
		}
		usleep(1000);
	}
	exit(0);
}
