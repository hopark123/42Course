/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:05:23 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 21:01:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_listnew(int num)
{
	t_list		*res;

	if (!ft_malloc(&res, sizeof(t_list)))
		return (0);
	res->num = num;
	res->next = res;
	res->prev = res;
	res->chunk = 0;
	return (res);
}

void	ft_listadd_front(t_list **list, t_list **new)
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
		(*list)->prev->next = (*new);
		(*new)->prev = (*list)->prev;
		(*list)->prev = (*new);
		(*new)->next = *list;
		(*list) = (*new);
	}
}

void	ft_listadd_back(t_list **list, t_list **new)
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

void	ft_listdelone(t_list **list)
{
	if ((*list) == 0)
		return ;
	ft_free(*list);
}

void	ft_listclear(t_list **list)
{
	t_list	*temp;
	t_list	*temp2;

	if (list == 0)
		return ;
	temp2 = (*list);
	while (*list)
	{
		if (((*list)->next))
			temp = (*list)->next;
		else
			temp = 0;
		ft_listdelone(list);
		*list = temp;
		if (temp2 == temp)
			break ;
	}
	*list = 0;
}
