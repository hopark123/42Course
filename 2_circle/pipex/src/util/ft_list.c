/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:27:39 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/13 18:04:00 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*ft_listnew(char *str)
{
	t_list		*res;

	if (!ft_malloc(&res, sizeof(t_list)))
		return (ERROR);
	res->str = str;
	res->next = 0;
	res->prev = 0;
	return (res);
}

void	ft_listadd_tail(t_list **list, t_list **new)
{
	t_list		*temp;

	if ((*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*list) = (*new);
		(*list)->next = 0;
		(*list)->prev = 0;
		(*list)->str = (*new)->str;
	}
	else
	{
		temp = (*list);
		while (temp && temp->next)
			temp = temp->next;
		(*new)->prev = temp;
		(*new)->next = temp->next;
		temp->next = (*new);
	}
}

void	ft_listdelone(t_list **list)
{
	if (list == 0 || (*list) == 0)
		return ;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	if ((*list)->prev)
		(*list)->prev->next = (*list)->next;
	if ((*list)->str)
		ft_free((*list)->str);
	(*list)->next = 0;
	(*list)->prev = 0;
	(*list)->str = 0;
	ft_free(*list);
	(*list) = 0;
}

void	ft_listclear(t_list **list)
{
	t_list		*temp;

	if (!list || !(*list))
		return ;
	temp = (*list);
	while ((*list) && list)
	{
		temp = temp->next;
		ft_listdelone(list);
		*list = temp;
	}
	*list = 0;
}

t_list	*ft_list_next(t_list *list, int n)
{
	t_list	*temp;

	temp = list;
	while (n--)
		temp = temp->next;
	return (temp);
}
