/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:07:26 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/24 14:50:57 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_try_fork(t_info *info, t_philo *philo)
{
	int		res;
	long	time;

	res = 0;
	time = ft_get_time();
	if (info->fork[philo->index] && info->fork[(philo->index + 1) % info->num])
	{
		pthread_mutex_lock(info->fork_m[philo->index]);
		ft_printf(info, time, philo->index, "has taken a fork(R)");
		pthread_mutex_lock(info->fork_m[(philo->index + 1) % info->num]);
		ft_printf(info, time, philo->index, "has taken a fork(L)");
		info->fork[philo->index] = 0;
		info->fork[(philo->index + 1)] = 0;
		res = 1;
	}
	return (res);
}

int	ft_drop_fork(t_info *info, t_philo *philo)
{
	pthread_mutex_unlock(info->fork_m[philo->index]);
	pthread_mutex_unlock(info->fork_m[(philo->index + 1) % info->num]);
	info->fork[philo->index] = 1;
	info->fork[(philo->index + 1) % info->num] = 1;
	return (0);
}

static void	ft_eat(t_info *info, t_philo *philo)
{
	int		res;
	long	time;

	res = ft_try_fork(info, philo);
	if (res)
	{
		time = ft_get_time();
		ft_printf(info, time, philo->index, "is eating");
		philo->last_eat = time;
		philo->full = 1;
		usleep((info->time_eat - 5) * 1000);
	}
}

static void	ft_sleep(t_info *info, t_philo *philo)
{
	long	time;

	time = ft_get_time();
	if (info->time_eat <= time - philo->last_eat)
	{
		ft_printf(info, time, philo->index, "is sleeping");
		ft_drop_fork(info, philo);
		philo->full = 2;
		usleep((info->time_sleep - 5) * 1000);
	}
}

static int	ft_think(t_info *info, t_philo *philo)
{
	int		res;
	long	time;

	res = 0;
	if (philo->full == 2)
	{
		time = ft_get_time();
		philo->full = 0;
		philo->cnt_eat++;
		if (info->must_eat >= 0 && philo->cnt_eat >= info->must_eat)
			res++;
		else
			ft_printf(info, time, philo->index, "is thinking");
	}
	return (res);
}

void	*ft_game(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = arg;
	info = philo->info;
	philo->alive = 1;
	pthread_create(&philo->tid, NULL, &ft_check_death, philo);
	while (info->alive)
	{
		if (philo->full == 0)
			ft_eat(info, philo);
		else if (philo->full == 1)
			ft_sleep(info, philo);
		else if (ft_think(info, philo))
			break ;
	}
	pthread_join(philo->tid, NULL);
	return (0);
}
