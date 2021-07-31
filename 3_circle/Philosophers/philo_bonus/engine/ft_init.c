/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 13:25:13 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/31 16:31:12 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_info2(t_info *info)
{
	char	*sem_name;

	sem_name = ft_strndup("philo", 5);
	sem_unlink(sem_name);
	info->sem = sem_open(sem_name, O_CREAT | O_EXCL, 0644, info->num);
	ft_free(sem_name);
	sem_name = ft_strndup("alive", 5);
	sem_unlink(sem_name);
	info->alive = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 0);
	ft_free(sem_name);
	sem_name = ft_strndup("print", 5);
	sem_unlink(sem_name);
	info->print_s = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1);
	ft_free(sem_name);
	return (SUCCESS);
}

static int	check_argv(char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (av[i][j])
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
	if (ac == 6)
		info->must_eat = (int)ft_atoi(av[5]);
	else
		info->must_eat = INT_MAX;
	if (!ft_malloc(&info->philo, sizeof(t_philo *) * info->num))
		return (ERROR);
	if (!ft_malloc(&info->pids, sizeof(int) * info->num))
		return (ERROR);
	return (init_info2(info));
}

t_philo	*ft_init_philo(t_info *info, int i)
{
	t_philo	*philo;

	if (!ft_malloc(&philo, sizeof(t_philo)))
		return (ERROR);
	philo->index = i;
	philo->full = 0;
	philo->check = 0;
	philo->fork = 0;
	philo->cnt_eat = 0;
	philo->last_eat = ft_get_time();
	philo->info = info;
	return (philo);
}
