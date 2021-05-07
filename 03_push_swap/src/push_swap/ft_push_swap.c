/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/07 16:46:54 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	main(int ac, char **av)
{
	static t_inf	*inf;
	int				i;

	i = 0;
	if (ac < 2)
		return (0);
	if (!ft_malloc(&inf, sizeof(t_inf)))
		return (ERROR);
	//ft_memset(&inf, 0, sizeof(t_inf));
	if (ft_strncmp(av[1], "-v", 2))
	{
		inf->bonus = 'v';
		i++;
	}
	else if (ft_strncmp(av[1], "-c", 2))
	{
		inf->bonus = 'c';
		i++;
	}
	ft_make_list(ac, av, inf);
	//ft_show(inf, "start");

	ft_sort_a(inf, 0);
	if (inf->bonus)
		ft_show(inf, "end");
}
