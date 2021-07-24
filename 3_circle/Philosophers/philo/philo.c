/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:23:12 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/24 14:51:08 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_info2(t_info *info, int ac, char **av)
{
	int		i;

	i = 0;
	if (!ft_malloc(&(info->philo), sizeof(t_philo *) * info->num))
		return ;
	if (!ft_malloc(&(info->tid), sizeof(pthread_t) * info->num))
		return ;
	if (!ft_malloc(&(info->fork_m), sizeof(pthread_mutex_t *) * info->num))
		return ;
	if (!ft_malloc(&(info->fork), sizeof(int *) * info->num))
		return ;
	i = 0;
	while (i < info->num)
	{
		info->fork[i] = 1;
		if (!ft_malloc(&info->fork_m[i], sizeof(pthread_mutex_t)))
			return ;
		pthread_mutex_init(info->fork_m[i], NULL);
		i++;
	}
	if (!ft_malloc(&info->print_m, sizeof(pthread_mutex_t)))
		return ;
	pthread_mutex_init(info->print_m, NULL);
}

static void	init_info(t_info *info, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return ;
	info->num = (int)ft_atoi(av[1]);
	info->time_start = ft_get_time();
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->alive = 1;
	if (ac == 6)
		info->must_eat = (int)ft_atoi(av[5]);
	else
		info->must_eat = -1;
	init_info2(info, ac, av);
}

static t_philo	*init_philo(t_info *info, int i)
{
	t_philo	*philo;

	if (!ft_malloc(&philo, sizeof(t_philo)))
		return (0);
	philo->index = i;
	philo->last_eat = ft_get_time();
	philo->cnt_eat = 0;
	philo->alive = 1;
	philo->full = 0;
	philo->info = info;
	return (philo);
}

int	main(int ac, char **av)
{
	t_info	*info;
	int		i;
	void	*ret;

	if (!ft_malloc(&info, sizeof(t_info)))
		return (0);
	init_info(info, ac, av);
	// test_list("a", info->head);
	// ft_listdelone((info->head->next->next));
	// test_list("g", info->head);
	i = 0;
	while (i < info->num)
	{
		info->philo[i] = init_philo(info, i);
		i++;
	}
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
	write(1,"end\n",4);
}
