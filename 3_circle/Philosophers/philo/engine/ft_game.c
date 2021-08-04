/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:07:26 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/31 18:29:55 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_info *info, t_philo *philo)
{
	long	res;

	res = ft_try_fork(info, philo);
	if (res)
	{
		ft_printf(info, philo->index, "is eating");
		philo->last_eat = res;
		philo->full = 1;
		ft_usleep((info->time_eat));
	}
}

static void	ft_sleep(t_info *info, t_philo *philo)
{
	long	time;

	time = ft_get_time();
	if (info->time_eat <= time - philo->last_eat)
	{
		ft_printf(info, philo->index, "is sleeping");
		ft_drop_fork(info, philo);
		philo->full = 2;
		ft_usleep(info->time_sleep);
	}
}

static int	ft_think(t_info *info, t_philo *philo)
{
	int		res;

	res = 0;
	if (philo->full == 2)
	{
		philo->full = 0;
		philo->cnt_eat++;
		if (info->must_eat >= 0 && philo->cnt_eat >= info->must_eat)
			res++;
		else
			ft_printf(info, philo->index, "is thinking");
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
