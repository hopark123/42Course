/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 13:49:49 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/31 16:23:04 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_try_fork(t_info *info, t_philo *philo)
{
	long	res;

	res = 0;
	if (philo->index % 2 == 1)
	{
		pthread_mutex_lock(info->fork_m[philo->index]);
		ft_printf(info, philo->index, "has taken fork");
		info->fork[philo->index] = 0;
		pthread_mutex_lock(info->fork_m[(philo->index + 1) % info->num]);
		info->fork[(philo->index + 1)] = 0;
		ft_printf(info, philo->index, "has taken fork");
	}
	else
	{
		pthread_mutex_lock(info->fork_m[(philo->index + 1) % info->num]);
		ft_printf(info, philo->index, "has taken fork");
		pthread_mutex_lock(info->fork_m[philo->index]);
		ft_printf(info, philo->index, "has taken fork");
	}
	res = ft_get_time();
	return (res);
}

int	ft_drop_fork(t_info *info, t_philo *philo)
{
	info->fork[philo->index] = 1;
	info->fork[(philo->index + 1) % info->num] = 1;
	pthread_mutex_unlock(info->fork_m[philo->index]);
	pthread_mutex_unlock(info->fork_m[(philo->index + 1) % info->num]);
	return (0);
}
