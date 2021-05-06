/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:05:23 by hopark            #+#    #+#             */
/*   Updated: 2021/05/03 15:40:30 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list			*ft_n_next_list(t_list *list, int n)
{
	while (n-- && list)
		list= list->next;
	return (list);
}

t_list			*ft_listnew(int num)
{
	t_list		*res;

	if (!(res = malloc(sizeof(t_list))))
		return (0);
	res->num = num;
	res->next = res;
	res->prev = res;
	res->chunk = 0;
	return (res);
}

t_list			*ft_listndup(t_list *list)
{
	t_list		*res;

	if (!(res = malloc(sizeof(t_list))))
		return (0);
	res->num = list->num;
	res->next = list->next;
	res->prev = list->prev;
	res->chunk = list->chunk;
	return (res);
}


void			ft_listadd_front(t_list **list, t_list **new)
{
	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*new)->next = (*new);
		(*new)->prev = (*new);
		(*list) = (*new);
	}
	else
	{
		//if ((*list)->prev)
		//{
		(*list)->prev->next = (*new);
		(*new)->prev = (*list)->prev;
		(*list)->prev = (*new);
		(*new)->next = *list;
		(*list) = (*new);
		//}
	}
}

void			ft_listadd_back(t_list **list, t_list **new)
{
	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*list) = (*new);
		(*list)->next = (*list);
		(*list)->prev = (*list);
	}
	else
	{
		(*list)->next->prev = (*new);
		(*new)->prev = (*list);
		(*new)->next = (*list)->next;
		(*list)->next = (*new);
	}
}

void			ft_listdelone(t_list **list)
{
	if ((*list) == 0)
		return ;
	ft_free(*list);
}

void			ft_listexcpet(t_list **list)
{
	t_list *temp;
	
	if ((*list) == 0)
		return ;
	if (((*list)->next))
		((*list)->next)->prev = (*list)->prev;
	if ((*list)->prev)
		((*list)->prev)->next = (*list)->next;

}

void			ft_listclear(t_list **list)
{
	t_list *temp;

	if (list == 0)
		return ;
	while (*list)
	{
		if (((*list)->next))
			temp = (*list)->next;
		else
			temp = 0;
		ft_listdelone(list);
		*list = temp;
	}
	*list = 0;
}