/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:55:36 by hopark            #+#    #+#             */
/*   Updated: 2020/10/03 19:54:40 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(lst, del);
		*lst = temp;
	}
	*lst = 0;
}
