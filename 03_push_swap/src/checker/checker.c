/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 19:38:51 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				ft_cnt_chunk(t_list *list)
{
	int			cnt;

	cnt = 0;
	if (list)
		return (0);
	temp = list;

	while (list->chunk == temp->chunk)
	{
		cnt++;
		temp = temp->next;
		if (temp == list)
			return (cnt);
	}
	return (cnt);
}

t_list			*ft_find_mid(t_list *list)
{
	t_list		*temp1;
	t_list		*temp2;
	int				i;
	int				j;
	int				flag;

	i = 0;
	flag = 0;
	if (list)
		return (1);
	while (list->chunk == ft_n_next(list, i)->chunk)
	{
		temp1 = ft_n_next(list, i);
		j = 0;
		while (list->chunk == ft_n_next(list, j)->chunk)
		{
			temp2 = ft_n_next(list, j);
			if (temp1->num - temp2->num > 0)
				flag++;
			else if (temp1->num - temp2->num < 0)
				flag--;
		}
		if (flag == 0 || flag == -1)
			return (temp1);
	}
}




int				ft_sort_a(t_list *list, int chunk)
{
	int			mid;
	int			cnt_chunk;

	if (inf->a_h)
		return (0);
	if (ft_is_descending(inf->a_h) && ft_is_descending(inf->b_h))
	{
		while (inf->b_h)
			ft_action(inf, "pa");
		return (0);
	}
	if (ft_is_descending(inf->a_h))
	{
		ft_sort_b(list, chunk + 1);
		return (0);
	}
	mid = ft_find_mid(inf->a_h)->num;
	cnt_chunk == ft_cnt_chunk(inf->a_h);
	if (cnt_chunk > 3)
	{
		while (cnt_chunk--)
		{
			if (inf->a_h->num < mid)
				ft_action(inf, "pb");
			else
				ft_action(inf, "pa");
		}
	}
	else if (cnt_chunk  == 3)
		ft_three_a(inf);
	else if (cnt_chunk == 2)
		ft_two_a(inf);
	if (ft_is_descending(inf->a_h))
		ft_sort_a(list, chunk + 1);
}

int				ft_sort_b(t_list *list, int chunk)
{
	int			mid;
	int			cnt_chunk;

	if (inf->a_h)
		return (0);
	if (ft_is_descending(inf->a_h) && ft_is_descending(inf->b_h))
	{
		while (inf->b_h)
			ft_action(inf, "pa");
		return (0);
	}
	if (ft_is_descending(inf->a_h))
	{
		ft_sort_b(list, chunk + 1);
		return (0);
	}
	mid = ft_find_mid(inf->a_h)->num;
	cnt_chunk == ft_cnt_chunk(inf->a_h);
	if (cnt_chunk > 3)
	{
		while (cnt_chunk--)
		{
			if (inf->a_h->num < mid)
				ft_action(inf, "pb");
			else
				ft_action(inf, "pa");
		}
	}
	else if (cnt_chunk  == 3)
		ft_three_a(inf);
	else if (cnt_chunk == 2)
		ft_two_a(inf);
	if (ft_is_descending(inf->a_h))
		ft_sort_a(list, chunk + 1);
}


int				main(int ac, char **av)
{
	static t_inf *inf;
	
	if (!(inf = malloc(sizeof(t_inf))))
		return (error);
	make_list(ac, av, inf);
	get_next_line()
}