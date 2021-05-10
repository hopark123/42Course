/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:51:46 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 15:52:36 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_n_next_list(t_list *list, int n)
{
	while (n-- && list)
		list = list->next;
	return (list);
}

void	ft_listexcpet(t_list **list)
{
	t_list	*temp;

	if ((*list) == 0)
		return ;
	if (((*list)->next))
		((*list)->next)->prev = (*list)->prev;
	if ((*list)->prev)
		((*list)->prev)->next = (*list)->next;
}
