/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:00:16 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/31 16:34:14 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_kill_all(void *arg)
{
	int		i;
	t_info	*info;

	info = (t_info *)arg;
	sem_wait(info->alive);
	i = 0;
	while (i < info->num && !info->kill)
	{
		kill(info->pids[i], 1);
		i++;
	}
	return (0);
}

int	ft_check_death(t_info *info, t_philo *philo)
{
	int		res;
	long	time;

	time = ft_get_time();
	res = 0;
	if (time - philo->last_eat > info->time_die)
	{
		ft_printf(info, time, philo->index, "died");
		sem_post(info->alive);
		info->alive = 0;
		res++;
	}
	return (res);
}
