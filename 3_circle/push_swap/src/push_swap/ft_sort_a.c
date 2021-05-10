/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:56:52 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 16:26:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_more_a(t_inf *inf, t_pivot pivot, int cnt_chunk, float chunk)
{
	while (cnt_chunk--)
	{
		if (inf->a_h->num < pivot.second)
		{
			inf->a_h->chunk = chunk;
			ft_action(inf, "pb");
			if (chunk == 0 && inf->b_h->num < pivot.first)
			{
				inf->b_h->chunk = chunk - 1;
				ft_action(inf, "rb");
			}
			else if (chunk != 0 && inf->b_h->num > pivot.first)
			{
				inf->b_h->chunk = chunk + 1;
				ft_action(inf, "rb");
			}
		}
		else
		{
			inf->a_h->chunk = chunk;
			ft_action(inf, "ra");
		}
	}
	ft_more_a2(inf);
	return ;
}

void	ft_more_a2(t_inf *inf)
{
	int				temp;

	if (inf->a_h->chunk == -5 && inf->a_t->chunk >= inf->b_h->chunk)
	{
		temp = inf->a_t->chunk;
		while (inf->a_t->chunk == temp)
			ft_action(inf, "rra");
	}
	return ;
}

void	ft_sort_a(t_inf *inf, float chunk)
{
	t_pivot		pivot;
	int			cnt_chunk;

	if (!inf->a_h)
		return ;
	ft_back_a(inf, chunk);
	while (!ft_chunk_is_descending(inf->b_h))
		ft_action(inf, "rrb");
	if (ft_sorted_already(inf))
		return ;
	pivot = ft_find_pivot(inf->a_h);
	cnt_chunk = ft_cnt_chunk(inf->a_h);
	if (cnt_chunk > 3)
		ft_more_a(inf, pivot, cnt_chunk, chunk);
	else if (cnt_chunk == 3)
		ft_three_a(inf, chunk);
	else if (cnt_chunk == 2)
		ft_two_a(inf, chunk);
	else
		inf->a_h->chunk = -5;
	ft_sort_a2(inf, chunk);
}

void	ft_sort_a2(t_inf *inf, float chunk)
{
	if (!ft_is_ascending(inf->a_h))
		ft_back_a(inf, chunk);
	ft_sorted_excpet(inf);
	if (!ft_is_ascending(inf->a_h))
		ft_sort_a(inf, chunk + 2);
	else
		ft_sort_b(inf, chunk + 2);
}
