/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:47:18 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 15:38:51 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	ft_isnew(t_inf *inf, int num)
{
	t_list	*temp;

	temp = inf->a_h;
	while (1)
	{
		if (temp->num == num)
			return (ERROR);
		temp = temp->next;
		if (temp == inf->a_h)
			return (SUCESS);
	}
	return (ERROR);
}

int	ft_make_list(char **av, t_inf *inf)
{
	int			i;

	i = 1;
	if (inf->bonus)
		i++;
	if (!ft_is_num(av[i]))
		return (ERROR);
	return (ft_make_list2(inf, av, i));
}

int	ft_make_list2(t_inf *inf, char **av, int i)
{
	t_list		*old;
	t_list		*new;
	int			num;

	num = ft_atoi(av[i]);
	old = ft_listnew(num);
	inf->a_h = old;
	while (av[++i])
	{
		if (!ft_is_num(av[i]))
			return (ERROR);
		num = ft_atoi(av[i]);
		inf->max = ft_max(2, num, inf->max);
		inf->min = ft_min(2, num, inf->min);
		if (!ft_isnew(inf, num))
			return (ERROR);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
	}
	ft_htsetting(inf);
	return (SUCESS);
}
