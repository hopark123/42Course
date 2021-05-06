/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:57:36 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 16:29:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_sort_b(t_inf *inf, float chunk)
{
	t_pivot		pivot;
	int			cnt_chunk;
	int			a_sort;
	int			b_sort;
	t_list		*temp2;

	if (!inf->b_h)
		return (0);
	while (!ft_chunk_is_descending(inf->b_h))
		ft_action(inf, "rrb");
	if (ft_is_ascending(inf->a_h))
	{
		temp2 = inf->a_h;
		while (1)
		{
			temp2->chunk = -5;
			temp2 = temp2->next;
			if (temp2->chunk == -5)
				break ;
		}
	}
	if (ft_is_ascending(inf->a_h) && ft_is_descending(inf->b_h))
	{
		while (inf->b_h)
			ft_action(inf, "pa");
		return (0);
	}
	pivot = ft_find_pivot(inf->b_h);
	cnt_chunk = ft_cnt_chunk(inf->b_h);
	if (cnt_chunk > 3)
	{
		while (cnt_chunk--)
		{
			if (inf->b_h->num > pivot.first)
			{
				inf->b_h->chunk = chunk + 1;
				ft_action(inf, "pa");
				if (inf->a_h->num < pivot.second)
				{
					inf->a_h->chunk = chunk + 1;
					ft_action(inf, "ra");
				}
			}
			else
			{
				inf->b_h->chunk = chunk;
				ft_action(inf, "rb");
			}
		}
		if (!ft_is_ascending(inf->a_h))
			ft_sort_a(inf, chunk + 2);
	}
	else if (cnt_chunk == 3)
		ft_three_b(inf, -5);
	else if (cnt_chunk == 2)
		ft_two_b(inf, -5);
	else
	{
		ft_action(inf, "pa");
		inf->a_h->chunk = -5;
	}
	if (!ft_is_ascending(inf->a_h))
		ft_sort_a(inf, chunk + 2);
	else
		ft_sort_b(inf, chunk + 2);
}
