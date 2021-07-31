/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philo_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:43:27 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/31 15:53:01 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free_philo(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num)
	{
		ft_free(info->philo[i]);
		i++;
	}
	ft_free(info->philo);
	ft_free(info->pids);
	ft_free(info);
}
