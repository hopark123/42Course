/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:47:18 by hopark            #+#    #+#             */
/*   Updated: 2021/05/13 13:59:40 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	ft_make_split(char **av, t_inf *inf)
{
	int			i;
	char		**split;

	split = av;
	i = 1;
	if (inf->bonus)
		i++;
	split = ft_split(av[i], ' ');
	i = 0;
	if (!ft_is_num(split[i]))
	{
		ft_free2(split, ft_strlen2(split));
		return (ERROR);
	}
	if (split)
		i = ft_make_split2(inf, split);
	ft_free2(split, ft_strlen2(split));
	return (i);
}

int	ft_make_split2(t_inf *inf, char **split)
{
	t_list		*old;
	t_list		*new;
	int			i;
	int			num;
	int			res;

	i = 0;
	res = 1;
	num = ft_atoi(split[i++]);
	old = ft_listnew(num);
	inf->a_h = old;
	while (split[i])
	{
		res *= ft_is_num(split[i]);
		num = ft_atoi(split[i]);
		inf->max = ft_max(2, num, inf->max);
		inf->min = ft_min(2, num, inf->min);
		res *= ft_isnew(inf, num);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
		i++;
	}
	ft_htsetting(inf);
	return (res);
}
