/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:09:17 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 15:13:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_a1(t_inf *inf)
{
	if (inf->a_h->num > inf->a_h->next->num)
	{
		ft_action(inf, "sa");
		if (inf->a_h->next->next == inf->a_t)
		{
			ft_action(inf, "rra");
			return ;
		}
		ft_action(inf, "ra");
		ft_action(inf, "sa");
		ft_action(inf, "rra");
		ft_action(inf, "sa");
	}
	else if (inf->a_h->num < inf->a_h->next->num)
	{
		if (inf->a_h->next->next == inf->a_t)
		{
			ft_action(inf, "rra");
			return ;
		}
		ft_action(inf, "ra");
		ft_action(inf, "sa");
		ft_action(inf, "rra");
		ft_action(inf, "sa");
	}
}

void	ft_three_a2(t_inf *inf)
{
	if (inf->a_h->num > inf->a_h->next->next->num)
	{
		if (inf->a_h->next->next == inf->a_t)
		{
			ft_action(inf, "rra");
			ft_action(inf, "rra");
			return ;
		}
		ft_action(inf, "sa");
		ft_action(inf, "ra");
		ft_action(inf, "sa");
		ft_action(inf, "rra");
	}
	else if (inf->a_h->num < inf->a_h->next->next->num)
		ft_action(inf, "sa");
}

void	ft_three_a3(t_inf *inf)
{
	if (inf->a_h->next->num > inf->a_h->next->next->num)
	{
		ft_action(inf, "ra");
		ft_action(inf, "sa");
		ft_action(inf, "rra");
	}
	else if (inf->a_h->next->num < inf->a_h->next->next->num)
		return ;
}

void	ft_three_a(t_inf *inf, float chunk)
{
	int			min;
	int			n1;
	int			n2;
	int			n3;

	n1 = inf->a_h->num;
	n2 = inf->a_h->next->num;
	n3 = inf->a_h->next->next->num;
	inf->a_h->chunk = -5;
	inf->a_h->next->chunk = -5;
	inf->a_h->next->next->chunk = -5;
	min = ft_min(3, n1, n2, n3);
	if (min == n3)
		ft_three_a1(inf);
	else if (min == n2)
		ft_three_a2(inf);
	else if (min == n1)
		ft_three_a3(inf);
}
