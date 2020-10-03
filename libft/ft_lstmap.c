/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:03:37 by hopark            #+#    #+#             */
/*   Updated: 2020/10/03 19:57:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (lst == 0 || f == 0)
		return (0);
	if (!(result = ft_lstnew(f(lst->content))))
		return (0);
	temp = result;
	lst = lst->next;
	while (lst)
	{
		if (!((temp->next) = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
