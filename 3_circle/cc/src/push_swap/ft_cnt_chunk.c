/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:53:04 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 16:27:34 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cnt_chunk(t_list *list)
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
