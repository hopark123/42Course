/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:09:17 by hopark            #+#    #+#             */
/*   Updated: 2021/05/05 16:42:58 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


void			ft_n_pa(t_inf *inf, int n)
{
	while (n--)
		ft_action(inf, "pa");
}


void			ft_three_b3(t_inf *inf)
{
	ft_action(inf, "pa");
	ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "pa");
}

void			ft_three_b4(t_inf *inf)
{
	ft_action(inf, "rb");
	ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "rrb");
	ft_action(inf, "pa");
	ft_action(inf, "pa");
}

void			ft_three_b5(t_inf *inf)
{
	ft_action(inf, "rb");
	ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "pa");
	ft_action(inf, "rrb");
	ft_action(inf, "pa");
}

void			ft_three_b6(t_inf *inf)
{
	ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "pa");
}

void			ft_three_b(t_inf *inf, float chunk)
{
	int			n1;
	int			n2;
	int			n3;
	int			min;

	printf("three_b\n");
	n1 = inf->b_h->num;
	n2 = inf->b_h->next->num;
	n3 = inf->b_h->next->next->num;
	inf->b_h->chunk = chunk;
	inf->b_h->next->chunk = chunk;
	inf->b_h->next->next->chunk = chunk;
	min = ft_min(3, n1, n2, n3);
	if (min == n3)
	{
		if (n1 < n2)
			ft_action(inf, "sb");
		ft_n_pa(inf, 3);
	}
	else if (min == n2)
	{
		if (n1 > n3)
			ft_three_b3(inf);
		else if (n1 < n3)
			ft_three_b4(inf);
		
	}
	else if (min == n1)
	{
		if (n2 < n3)
			ft_three_b5(inf);
		else if (n2 > n3)
			ft_three_b6(inf);
	}
}
