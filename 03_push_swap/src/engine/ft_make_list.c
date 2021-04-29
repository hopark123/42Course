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
	num = ft_atoi(av[++i]);
	old = ft_listnew(num);
	inf->a_h = old;
	i = 0;
	while (av[++i])
	{
		num = ft_atoi(av[i]);
		printf("%d\n", num);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
		inf->a_t = new;

	}
	inf->a_t->next = inf->a_h;
	inf->a_h->prev = inf->a_t;
	t_list *temp = inf->a_t;
	while (temp->next != inf->a_t)
	{
		printf("%d\n", temp->num);
		temp = temp->next;
	}
}