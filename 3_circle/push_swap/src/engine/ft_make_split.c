/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:47:18 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 20:49:28 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	ft_make_split(char **av, t_inf *inf)
{
	int			i;
	char		**split;

	i = 1;
	if (inf->bonus)
		i++;
	split = ft_split(av[i], ' ');
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

	i = 0;
	num = ft_atoi(split[i]);
	if (!ft_is_num(split[i]))
		return (ERROR);
	old = ft_listnew(num);
	inf->a_h = old;
	while (split[++i])
	{
		if (!ft_is_num(split[i]))
			return (ERROR);
		num = ft_atoi(split[i]);
		if (!ft_isnew(inf, num))
			return (ERROR);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
		inf->a_t = new;
	}
	ft_htsetting(inf);
	return (SUCESS);
}