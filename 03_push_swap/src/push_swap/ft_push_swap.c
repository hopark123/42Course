/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 17:37:08 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
int	ft_bonus_check(char **av, t_inf *inf)
{
	int		i;

	i = 0;
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
	return (i);
}

int	main(int ac, char **av)
{
	static t_inf	*inf;
	int				i;
	int				res;

	i = 0;
	if (ac < 2)
		return (0);
	if (!ft_malloc(&inf, sizeof(t_inf)))
		return (ERROR);
	i += ft_bonus_check(av, inf);
	if (ac == i + 2)
		res = ft_make_split(ac, av, inf);
	else
		res = ft_make_list(ac, av, inf);
	if (res == ERROR)
	{
		write(1, "Error", 5);
		return (0);
	}
	ft_sort_a(inf, 0);
	if (inf->bonus)
		ft_show(inf, "end");
}
