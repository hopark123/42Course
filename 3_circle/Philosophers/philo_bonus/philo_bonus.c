/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:04:27 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/30 18:58:20 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_philo(t_info *info, int i)
{
	t_philo	*philo;

	philo = ft_init_philo(info, i);
	if (philo == ERROR)
		return (ERROR);
	info->philo[i] = philo;
	info->pids[i] = fork();
	if (!info->pids[i])
	{
		ft_game(philo);
		exit(0);
	}
}

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

int	main(int ac, char **av)
{
	t_info	*info;
	int		i;
	void	*ret;

	if (!ft_malloc(&info, sizeof(t_info)))
		return (1);
	if (init_info(info, ac, av) == ERROR)
		return (1);
	i = 0;
	while (i < info->num)
	{
		ft_philo(info, i);
		i++;
	}
	info->kill = 0;
	pthread_create(&info->tid, NULL, &ft_kill_all, info);
	i = 0;
	while (i < info->num)
	{
		waitpid((pid_t)info->pids[i], &info->pids[i], 0);
		i++;
	}
	info->kill = 1;
	sem_post(info->alive);
	pthread_join(info->tid, NULL);
	return (0);
}
