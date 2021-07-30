/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:58:00 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/30 17:58:35 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_try_fork(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)arg;
	info = philo->info;
	sem_wait(info->sem);
	sem_wait(info->sem);
	ft_printf(info, ft_get_time(), philo->index, "has taken fork1");
	ft_printf(info, ft_get_time(), philo->index, "has taken fork2");
	philo->fork = 1;
	philo->check = 0;
	return (0);
}

void	ft_drop_fork(t_info *info, t_philo *philo)
{
	sem_post(info->sem);
	sem_post(info->sem);
	philo->fork = 0;
}
