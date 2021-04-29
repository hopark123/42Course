/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:44:28 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 18:47:35 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				ft_is_ascending(t_list *list)
{
	t_list		*temp;

	if (list)
		return (1);
	temp = list;
	while (temp->next != list)
	{
		if (temp->num - temp->next->num < 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int				ft_is_descending(t_list *list)
{
	t_list		*temp;

	if (list)
		return (1);
	temp = list;
	while (temp->next != list)
	{
		if (temp->num - temp->next->num > 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int				ft_chunk_is_descending(t_list *list)
{
	t_list		*temp;

	if (list)
		return (1);
	temp = list;
	while (temp->next != list)
	{
		if (temp->chunk - temp->next->chunk < 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}