/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:58:55 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/30 18:26:45 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_think(t_info *info, t_philo *philo)
{
	int		res;
	long	time;

	time = ft_get_time();
	res = 0;
	if (philo->full == 2 && time - philo->last_eat >= info->time_eat + info->time_sleep)
	{
		philo->full = 0;
		philo->cnt_eat++;
		if (info->must_eat >= 0 && philo->cnt_eat >= info->must_eat)
			res++;
		else
			ft_printf(info, ft_get_time(), philo->index, "is thinking");
	}
	return (res);
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
	}
}

static void	ft_eat(t_info *info, t_philo *philo)
{
	long	time;

	time = ft_get_time();
	if (!philo->check)
	{
		if (!philo->fork)
		{
			philo->check = 1;
			pthread_create(&philo->tid, NULL, &ft_try_fork, philo);
		}
		else
		{
			pthread_join(philo->tid, NULL);
			ft_printf(info, time, philo->index, "is eating");
			philo->last_eat = time;
			philo->full = 1;
		}
	}
}

void	*ft_game(t_philo *philo)
{
	t_info	*info;
	long	time;

	info = philo->info;
	if ((philo->index % 2))
		ft_usleep(info->time_eat);
	while (1)
	{
		time = ft_get_time();
		if (ft_check_death(info, philo))
			break ;
		if (philo->full == 0)
			ft_eat(info, philo);
		else if (philo->full == 1)
			ft_sleep(info, philo);
		else if (ft_think(info, philo))
			break ;
	}
}
