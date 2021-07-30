/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:59:49 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/30 18:15:42 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_printf(t_info *info, long time, int index, char *str)
{
	sem_wait(info->print_s);
	time = ft_get_time();
	printf("%ld %d %s\n", time - info->time_start, index + 1, str);
	if (!ft_strncmp(str, "died", 5))
		sem_post(info->print_s);
}
