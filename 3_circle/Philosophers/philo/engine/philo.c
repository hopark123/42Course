/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:23:12 by hjpark            #+#    #+#             */
/*   Updated: 2021/08/13 13:32:28 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	*info;
	int		i;
	void	*ret;

	if (!ft_malloc(&info, sizeof(t_info)))
		return (1);
	if (init_info(info, ac, av) == ERROR)
		return (1);
	init_philo(info);
	i = 0;
	while (i < info->num)
	{
		pthread_create(&info->tid[i], NULL, &ft_game, info->philo[i]);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < info->num)
		pthread_join(info->tid[i++], &ret);
	ft_free_philo(info);
}
