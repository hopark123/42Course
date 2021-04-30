/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/04/30 16:14:55 by hopark           ###   ########.fr       */
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

t_list			*ft_find_mid(t_list *list)
{
	t_list			*temp1;
	t_list			*temp2;
	int				i;
	int				j;
	int				flag;
	int				cnt_chunk;
	i = 0;
	flag = 0;
	if (!list)
		return (0);
	cnt_chunk = ft_cnt_chunk(list);
	while (i < cnt_chunk)
	{
		temp1 = ft_n_next(list, i);
		j = 0;
		flag = 0;
		while (j < cnt_chunk)
		{
			temp2 = ft_n_next(list, j);
			if (temp1->num - temp2->num > 0)
				flag++;
			else if (temp1->num - temp2->num < 0)
				flag--;
			j++;

		}
		i++;
		if (flag == 0 || flag == 1)
			return (temp1);
	}
}


int				ft_sort_a(t_inf *inf, int chunk)
{
	int			mid;
	int			cnt_chunk;


	//write(1, "-------astart-----\n",20);
	if (!inf->a_h)
		return (0);
	while (!ft_chunk_is_descending(inf->a_h))
		ft_action(inf, "rra");
	if (ft_is_ascending(inf->a_h) && ft_is_descending(inf->b_h))
	{
		while (inf->b_h)
			ft_action(inf, "pa");
		return (0);
	}
	mid = ft_find_mid(inf->a_h)->num;
	cnt_chunk = ft_cnt_chunk(inf->a_h);
	if (cnt_chunk > 3)
	{
		while (cnt_chunk--)
		{
				//printf("# a  now : %d mid : %d #\n",inf->a_h->num, mid);
			if (inf->a_h->num < mid)
			{
				inf->a_h->chunk = chunk;
				ft_action(inf, "pb");
			}
			else
			{
				inf->a_h->chunk = chunk;
				ft_action(inf, "ra");
			}
		}
	}
	else if (cnt_chunk  == 3)
		ft_three_a(inf);
	else if (cnt_chunk == 2)
		ft_two_a(inf);
	if (!ft_is_ascending(inf->a_h))
		ft_sort_a(inf, chunk + 1);
	if (!ft_is_descending(inf->b_h))
		ft_sort_b(inf, chunk + 1);

}

int				ft_sort_b(t_inf *inf, int chunk)
{
	int			mid;
	int			cnt_chunk;

	//write(1, "-------bstart-----\n",20);

	if (!inf->b_h)
		return (0);
	while (!ft_chunk_is_descending(inf->b_h))
		ft_action(inf, "rrb");
	if (ft_is_ascending(inf->a_h) && ft_is_descending(inf->b_h))
	{
		while (inf->b_h)
			ft_action(inf, "pa");
		return (0);
	}
	mid = ft_find_mid(inf->b_h)->num;
	cnt_chunk = ft_cnt_chunk(inf->b_h);
	if (cnt_chunk > 3)
	{
		while (cnt_chunk--)
		{
				//printf("# b now : %d mid : %d #\n",inf->a_h->num, mid);
			if (inf->b_h->num > mid)
			{
				inf->b_h->chunk = chunk + 1;
				ft_action(inf, "pa");
			}
			else
			{
				inf->b_h->chunk = chunk + 1;
				ft_action(inf, "rb");
			}
		}
	}
	else if (cnt_chunk  == 3)
		ft_three_b(inf);
	else if (cnt_chunk == 2)
		ft_two_b(inf);
	if (!ft_is_ascending(inf->a_h))
		ft_sort_a(inf, chunk + 1);
	if (!ft_is_descending(inf->b_h))
		ft_sort_b(inf, chunk + 1);
}


 int				main(int ac, char **av)
 {
 	static t_inf *inf;
	
 	if (!(inf = malloc(sizeof(t_inf))))
 		return (ERROR);
 	ft_make_list(ac, av, inf);
 	ft_show(inf, "start");
 	ft_sort_a(inf, 0);
	//ft_is_ascending(inf->a_h);
 	//get_next_line()
 }
//int			main()
//{
//	t_list	*list1;
//	t_list	*list2;
//	t_list	*list3;
//	t_list	*list4;
//	t_list	*list5;
//	t_list	*list6;

	
//	int			i = 1;
//	list1 = ft_listnew(1);
//	list2 = ft_listnew(2);
//	list3 = ft_listnew(3);
//	list4 = ft_listnew(4);
//	list5 = ft_listnew(5);

//	ft_listadd_back(&list4, &list3);
//	ft_listadd_back(&list4, &list5);
//	ft_listadd_front(&list3, &list2);
//	ft_listadd_front(&list2, &list1);

//	t_list *temp = list1;
//	while (temp&& i < 7)
//	{
//		printf("now  : %d | ", temp->num);
//		if (temp->prev)
//			printf("prev : %d | ", temp->prev->num);
//		else
//			printf("prev : %d | ", 0);

//		if (temp->next)
//			{
//				printf("next : %d | ", temp->next->num);
//			}
//		else
//			printf("next : %d | ", 0);
//		printf("\n");
//		temp = temp->next;
//		if (temp == list1)
//			break;
//		i++;
//	}
//	printf("----------\n");
//	t_list	*lit1;
//	t_list	*lit2;
//	t_list	*lit3;
//	t_list	*lit4;
//	t_list	*lit5;
//	t_list	*lit6;

	
//	lit1 = ft_listnew(6);
//	lit2 = ft_listnew(7);
//	lit3 = ft_listnew(8);
//	lit4 = ft_listnew(9);
//	lit5 = ft_listnew(0);

//	ft_listadd_back(&lit4, &lit3);
//	ft_listadd_back(&lit4, &lit5);
//	ft_listadd_front(&lit3, &lit2);
//	ft_listadd_front(&lit2, &lit1);

//	// ft_listexcpet(&lit2);
//	//ft_push_tool(&lit1, &list1);
//	 ft_swap_tool(&lit1);
//	//ft_revrotate_tool(&lit1, &lit5);
//	temp = lit1;
//	i = 0;
//	while (temp && i < 7)
//	{
//		printf("now  : %d | ", temp->num);
//		if (temp->prev)
//			printf("prev : %d | ", temp->prev->num);
//		else
//			printf("prev : %d | ", 0);

//		if (temp->next)
//			{
//				printf("next : %d | ", temp->next->num);
//			}
//		else
//			printf("next : %d | ", 0);
//			temp = temp->next;
//		printf("\n");
//		if (temp == lit1)
//			break;
//		i++;
//	}
//}