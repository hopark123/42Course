/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 13:54:36 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/25 13:54:48 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num)
	{
		ft_free(info->philo[i]);
		ft_free(info->fork_m[i]);
		i++;
	}
	ft_free(info->philo);
	ft_free(info->fork_m);
	ft_free(info->fork);
	ft_free(info->print_m);
	ft_free(info);
}
