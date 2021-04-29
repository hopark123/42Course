/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:47:18 by hopark            #+#    #+#             */
/*   Updated: 2021/04/29 15:58:29 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			ft_make_list(int ac, char **av, t_inf *inf)
{
	t_list		*old;
	t_list		*new;
	int			i;
	int			num;
	num = ft_atoi(av[++i]);
	old = ft_listnew(num);
	inf->a_h = old;
	i = 1;
	while (av[++i])
	{
		num = ft_atoi(av[i]);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
		inf->a_t = new;
	}
	inf->b_h = 0;
	inf->b_t = 0;
	ft_htsetting(inf);
}