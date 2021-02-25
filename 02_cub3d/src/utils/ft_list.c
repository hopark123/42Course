/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:29:20 by hopark            #+#    #+#             */
/*   Updated: 2021/02/20 11:37:58 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list			*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list			*ft_lstnew(void *content)
{
	t_list		*result;

	if (!(result = malloc(sizeof(t_list))))
		return (0);
	result->content = content;
	result->next = 0;
	return (result);
}

void			ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

void			ft_lstdelone(t_list *lst)
{
	if (lst == 0)
		return ;
	free(lst->content);
	free(lst);
}

void			ft_lstclear(t_list **lst)
{
	t_list *temp;

	if (lst == 0)
		return ;
	while (*lst)
	{
		if (!(*lst)->next)
			temp = (*lst)->next;
		else
			temp = 0;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	*lst = 0;

}