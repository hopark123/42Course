/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 13:25:13 by hjpark            #+#    #+#             */
/*   Updated: 2021/08/04 17:20:33 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_info2(t_info *info)
{
	int		i;

	i = 0;
	if (!ft_malloc(&(info->philo), sizeof(t_philo *) * info->num))
		return (ERROR);
	if (!ft_malloc(&(info->tid), sizeof(pthread_t) * info->num))
		return (ERROR);
	if (!ft_malloc(&(info->fork_m), sizeof(pthread_mutex_t *) * info->num))
		return (ERROR);
	if (!ft_malloc(&(info->fork), sizeof(int *) * info->num))
		return (ERROR);
	i = 0;
	while (i < info->num)
	{
		info->fork[i] = 1;
		if (!ft_malloc(&info->fork_m[i], sizeof(pthread_mutex_t)))
			return (ERROR);
		pthread_mutex_init(info->fork_m[i], NULL);
		i++;
	}
	if (!ft_malloc(&info->print_m, sizeof(pthread_mutex_t)))
		return (ERROR);
	pthread_mutex_init(info->print_m, NULL);
	return (SUCCESS);
}

static int	check_argv(char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	init_info(t_info *info, int ac, char **av)
{
	if (ac < 5 || ac > 6 || check_argv(av) == ERROR)
		return (ERROR);
	info->num = (int)ft_atoi(av[1]);
	info->time_start = ft_get_time();
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	if (!info->num)
		return (ERROR);
	info->alive = 1;
	if (ac == 6)
		info->must_eat = (int)ft_atoi(av[5]);
	else
		info->must_eat = INT_MAX;
	return (init_info2(info));
}

void	init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < info->num)
	{
		if (!ft_malloc(&philo, sizeof(t_philo)))
			return ;
		philo->index = i;
		philo->last_eat = ft_get_time();
		philo->cnt_eat = 0;
		philo->alive = 1;
		philo->full = 0;
		philo->info = info;
		info->philo[i] = philo;
		i++;
	}
}
