/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:56:52 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 16:32:36 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_sort_a(t_inf *inf, float chunk)
{
	t_pivot		pivot;
	int			cnt_chunk;
	float		temp;
	t_list		*temp2;

	if (!inf->a_h)
		return (0);
	if (inf->a_h->chunk == -5)
	{
		if (inf->a_t->chunk > inf->b_h->chunk)
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
	while (!ft_chunk_is_descending(inf->b_h))
		ft_action(inf, "rrb");
	if (ft_is_ascending(inf->a_h) && ft_is_descending(inf->b_h))
	{
		while (inf->b_h)
			ft_action(inf, "pa");
		return (0);
	}
	pivot = ft_find_pivot(inf->a_h);
	cnt_chunk = ft_cnt_chunk(inf->a_h);
	if (cnt_chunk > 3)
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
		if (inf->a_h->chunk == -5 && inf->a_t->chunk >= inf->b_h->chunk)
		{
			temp = inf->a_t->chunk;
			while (inf->a_t->chunk == temp)
				ft_action(inf, "rra");
		}
		if (!ft_is_ascending(inf->a_h))
			ft_sort_a(inf, chunk + 2);
		else
			ft_sort_b(inf, chunk + 2);
		while (!ft_chunk_is_descending(inf->b_h))
			ft_action(inf, "rrb");
	}
	else if (cnt_chunk == 3)
		ft_three_a(inf, chunk);
	else if (cnt_chunk == 2)
		ft_two_a(inf, chunk);
	else
	{
		inf->a_h->chunk = -5;
		ft_back_a(inf, chunk);
	}
	temp2 = inf->a_h;
	if (ft_is_ascending(inf->a_h))
	{
		while (1)
		{
			temp2->chunk = -5;
			temp2 = temp2->next;
			if (temp2->chunk == -5)
				break ;
		}
	}
	if (!ft_is_ascending(inf->a_h))
		ft_sort_a(inf, chunk + 2);
	else
		ft_sort_b(inf, chunk + 2);
}
