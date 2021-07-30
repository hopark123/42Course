/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:06:23 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/24 17:13:47 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf(t_info *info, int index, char *str)
{
	long	time;

	time = ft_get_time();
	pthread_mutex_lock(info->print_m);
	if (info->alive)
		printf("%ld %d %s\n", time - info->time_start, index + 1, str);
	pthread_mutex_unlock(info->print_m);
}
