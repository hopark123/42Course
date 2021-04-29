/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:47:18 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 19:38:24 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			ft_make_list(int ac, char **av, t_inf *inf)
{
	t_list		*old;
	t_list		*new;
	int			i;
	int			num;
	
	old = 0;
	inf->a_h = old;
	i = 0;
	while (av[++i])
	{
		num = ft_atoi(av[++i]);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
		inf->b_h = new;
	}
	inf->b_h->next = inf->a_h;
	inf->a_h->prev = inf->b_h;
}