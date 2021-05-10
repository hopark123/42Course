/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:57:36 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 16:28:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
void	ft_more_b(t_inf *inf, t_pivot pivot, int cnt_chunk, float chunk)
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

void	ft_sort_b(t_inf *inf, float chunk)
{
	t_pivot		pivot;
	int			cnt_chunk;

	if (!inf->b_h)
		return ;
	while (!ft_chunk_is_descending(inf->b_h))
		ft_action(inf, "rrb");
	ft_sorted_excpet(inf);
	pivot = ft_find_pivot(inf->b_h);
	cnt_chunk = ft_cnt_chunk(inf->b_h);
	if (cnt_chunk > 3)
		ft_more_b(inf, pivot, cnt_chunk, chunk);
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
