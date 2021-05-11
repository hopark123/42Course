/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 16:17:52 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ac < 2 || !ft_malloc(&inf, sizeof(t_inf)))
	{
		write(2, "Error\n", 7);
		return (0);
	}
	ft_inf_init(inf);
	i += ft_bonus_check(av, inf);
	if (ac == i + 2)
		res = ft_make_split(av, inf);
	else
		res = ft_make_list(av, inf);
	if (res == ERROR)
		ft_exit(inf, "Error\n", 2);
	ft_sort_a(inf, 0);
	if (inf->bonus)
		ft_show(inf, "end");
	ft_exit(inf, 0, 1);
}
