/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 12:13:45 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				ft_cnt_chunk(t_list *list)
{
	int			cnt;
	t_list		*temp;
	cnt = 0;
	if (!list)
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

t_pivot			ft_find_pivot(t_list *list)
{
	int				i;
	int				cnt_chunk;
	int				*arr;
	t_pivot			res;
	i = 0;
	if (!list)
		return (res);
	cnt_chunk = ft_cnt_chunk(list);
	if (!(arr = malloc(sizeof(int) * cnt_chunk)))
		return	(res);
	
	while (i < cnt_chunk)
	{
		arr[i] = ft_n_next_list(list, i)->num;
		i++;
	}
	ft_bubblesort(arr, cnt_chunk);

	i = (int)(cnt_chunk / 3);
	res.first = arr[cnt_chunk / 3];
	i = (int)(cnt_chunk / 3 * 2);
	res.second = arr[cnt_chunk / 3 * 2];
	return (res);
}

void			ft_back_a(t_inf *inf, float chunk)
{
	float			temp;

	temp = inf->a_t->chunk;
	if (!inf->b_h)
		return ;
	if (inf->a_h->chunk != -5 && !ft_is_ascending(inf->a_h) && inf->a_t->chunk > inf->b_h->chunk)
	{
		while (1)
		{
				write(1,"GGG\n",4);

			ft_action(inf, "rra");
			inf->a_h->chunk = temp;
			if (temp != inf->a_t->chunk)
				return ;
		}
	}
}

int				ft_sort_a(t_inf *inf, float chunk)
{
	t_pivot		pivot;
	int			cnt_chunk;
	float		temp;
	write(1, "-------astart--------------------------------------------------------------------\n",83);
	ft_show(inf, "a");

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
					break;
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
	int i = 0;
	t_list		*temp2;

	pivot = ft_find_pivot(inf->a_h);
	cnt_chunk = ft_cnt_chunk(inf->a_h);
	if (cnt_chunk > 3)
	{
		while (cnt_chunk--)
		{
			i = 0;
				printf("# a  now : %d pivot : %d %d  chunk : %f#\n",inf->a_h->num, pivot.first, pivot.second, chunk);
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
				i++;
			}
		}
		if (inf->a_h->chunk == -5 && inf->a_t->chunk >= inf->b_h->chunk)
		{
			temp = inf->a_t->chunk;
			while (inf->a_t->chunk == temp)
			{
				write(1,"^^^^^^^^\n",10);
				ft_action(inf, "rra");
			}
		}
		if (!ft_is_ascending(inf->a_h))
			ft_sort_a(inf, chunk + 2);
		else
			ft_sort_b(inf, chunk + 2);
		while (!ft_chunk_is_descending(inf->b_h))
			ft_action(inf, "rrb");
	}
	else if (cnt_chunk  == 3)
	{	
		ft_three_a(inf, -5);
		ft_back_a(inf, chunk);
	}
	else if (cnt_chunk == 2)
	{
		ft_two_a(inf, -5);
		ft_back_a(inf, chunk);

	}
	else
	{
			ft_back_a(inf, chunk);
	}
	
	//if (inf->a_h->chunk != -5)
	//{
	//	temp2 = inf->a_t;
	//	while (temp == inf->a_t->chunk)
	//	{
	//		ft_action(inf, "rra");
	//		inf->a_h->chunk = chunk + 2;
	//		temp2 = temp2->next;
	//		return (0);
	//	}
	//}	

	temp2 = inf->a_h;
	if (ft_is_ascending(inf->a_h))
	{
		write(1,"@@@@@@\n",8);
		while (1)
		{
			temp2->chunk = -5;
			temp2 = temp2->next;
			if (temp2->chunk == -5)
				break;
		}
	}
	if (!ft_is_ascending(inf->a_h))
		ft_sort_a(inf, chunk + 2);
	else
		ft_sort_b(inf, chunk + 2);
}

int				ft_sort_b(t_inf *inf, float chunk)
{
	t_pivot		pivot;
	int			cnt_chunk;
	int			a_sort;
	int			b_sort;

	write(1, "-------bstart--------------------------------------------------\n",65);
	ft_show(inf, "b");
	if (!inf->b_h)
		return (0);
	while (!ft_chunk_is_descending(inf->b_h))
		ft_action(inf, "rrb");
	t_list		*temp2;
	temp2 = inf->a_h;
	if (ft_is_ascending(inf->a_h))
	{
		write(1,"@@@@@@\n",8);

		while (1)
		{
			temp2->chunk = -5;
			temp2 = temp2->next;
			if (temp2->chunk == -5)
				break;
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
				printf("# b now : %d pivot : %d %d chunk %f#\n",inf->b_h->num, pivot.first, pivot. second, chunk);
			if (inf->b_h->num >= pivot.first)
			{
				inf->b_h->chunk = chunk + 1;
				ft_action(inf, "pa");
				if (inf->a_h->num <= pivot.second)
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
		//while (!ft_chunk_is_descending(inf->a_h))
		//{
		//		write(1,"GGG\n",4);
		//	ft_action(inf, "rra");
		//}
	}
	else if (cnt_chunk  == 3)
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


 int				main(int ac, char **av)
 {
 	static t_inf	*inf;
 	if (!(inf = malloc(sizeof(t_inf))))
 		return (ERROR);
 	ft_make_list(ac, av, inf);
 	ft_show(inf, "start");
 	ft_sort_a(inf, 0);
 	ft_show(inf, "end");

 	//get_next_line()
 }