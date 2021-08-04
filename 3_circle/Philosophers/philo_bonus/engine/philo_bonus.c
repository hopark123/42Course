/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:04:27 by hjpark            #+#    #+#             */
/*   Updated: 2021/08/04 16:49:53 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_wait(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num)
	{
		waitpid((pid_t)info->pids[i], &info->pids[i], 0);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (!ft_malloc(&info, sizeof(t_info)))
		return (1);
	if (init_info(info, ac, av) == ERROR)
		return (1);
	ft_philo_bonus(info);
	info->kill = 0;
	pthread_create(&info->tid, NULL, &ft_kill_all, info);
	ft_wait(info);
	info->kill = 1;
	sem_post(info->alive);
	pthread_join(info->tid, NULL);
	ft_free_philo(info);
	return (0);
}
