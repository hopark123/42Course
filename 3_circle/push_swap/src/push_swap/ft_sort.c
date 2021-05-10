/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:54:59 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 15:58:09 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_back_a(t_inf *inf, float chunk)
{
	float		temp;

	if (inf->a_h->chunk == -5)
	{
		if (!inf->b_h || inf->a_t->chunk > inf->b_h->chunk)
		{
			temp = inf->a_t->chunk;
			while (1)
			{
				ft_action(inf, "rra");
				inf->a_h->chunk = temp;
				if (temp != inf->a_t->chunk)
					break ;
			}
		}
		else
			ft_sort_b(inf, chunk);
	}
}

int	ft_sorted_already(t_inf *inf)
{
	if (ft_is_ascending(inf->a_h) && ft_is_descending(inf->b_h))
	{
		while (inf->b_h)
			ft_action(inf, "pa");
		return (SUCESS);
	}
	return (ERROR);
}

void	ft_sorted_excpet(t_inf *inf)
{
	t_list		*temp;

	temp = inf->a_h;
	if (ft_is_ascending(inf->a_h))
	{
		while (1)
		{
			temp->chunk = -5;
			temp = temp->next;
			if (temp->chunk == -5)
				break ;
		}
	}
}
