/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:09:17 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 19:38:22 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


void			ft_three_a1(t_inf *inf)
{
	ft_action(inf, "ra");
	ft_action(inf, "sa");
	ft_action(inf, "rra");
}

{
	ft_action(inf, "ra");
	ft_action(inf, "sa");
	ft_action(inf, "pb");
	ft_action(inf, "rra");
	ft_action(inf, "sa");
	ft_action(inf, "pa");
}


void			ft_three_a2(t_inf *inf)
{
	ft_action(inf, "ra");
	ft_action(inf, "sa");
	ft_action(inf, "rra");
	ft_action(inf, "sa");
}

void			ft_three_a3(t_inf *inf)
{
	ft_action(inf, "sa");
	ft_action(inf, "ra");
	ft_action(inf, "sa");
	ft_action(inf, "rra");
}

void			ft_three_a5(t_inf *inf)
{
	ft_action(inf, "ra");
	ft_action(inf, "sa");
	ft_action(inf, "rra");
}

void			ft_three_a(t_inf *inf)
{
	int			n1;
	int			n2;
	int			n3;
	int			min;

	n1 = inf->a_h->num;
	n2 = inf->a_h->next->num;
	n3 = inf->a_h->next->next->num;

	min = ft_min(3, n1, n2, n3)
	if (min == n3)
	{
		if (n1 > n2)
			ft_three_a1(inf);
		else if (n1 < n2)
			ft_three_a2(inf);
	}
	else if (min == n2)
	{
		if (n1 > n3)
			ft_three_a3(inf);
		else if (n1 < n3)
			ft_action(inf, "sa");
	}
	else if (min == n1)
	{
		if (n2 < n3)
			ft_three_a5(inf);
		else (n2 > n3)
			return ;
	}
}
