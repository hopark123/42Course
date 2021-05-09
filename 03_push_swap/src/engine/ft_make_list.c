/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:47:18 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 13:03:39 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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

int	ft_make_list(int ac, char **av, t_inf *inf)
{
	t_list		*old;
	t_list		*new;
	int			i;
	int			num;

	i = 1;
	if (inf->bonus)
		i++;
	if (!ft_is_num(av[i]))
		return (ERROR);
	num = ft_atoi(av[i]);
	old = ft_listnew(num);
	inf->a_h = old;
	while (av[++i])
	{
		if (!ft_is_num(av[i]))
			return (ERROR);
		num = ft_atoi(av[i]);
		if (!ft_isnew(inf, num))
			return (ERROR);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
		inf->a_t = new;
	}
	inf->b_h = 0;
	inf->b_t = 0;
	ft_htsetting(inf);
	return (SUCESS);
}
