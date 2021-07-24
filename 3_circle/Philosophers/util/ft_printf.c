/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:06:23 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/23 16:27:34 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf(t_info *info, long time, int index, char *str)
{
	pthread_mutex_lock(info->print_m);
	if (info->alive)
		printf("%5ld %2d %s\n", time - info->time_start, index + 1, str);
	pthread_mutex_unlock(info->print_m);
}
