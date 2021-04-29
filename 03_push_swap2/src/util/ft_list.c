/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:29:20 by hopark            #+#    #+#             */
/*   Updated: 2021/04/15 16:38:18 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	int				num;
	struct s_list	*prev;
	struct s_list	*next;

}				t_list;
void				ft_free(void *memory)
{
	if (memory)
		free(memory);
}

void				ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
			ft_free(s[i]);
	}
	ft_free(s);
}

t_list			*ft_listlast(t_list *list)
{
	if (list == 0)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

t_list			*ft_listnew(int num)
{
	t_list		*res;

	if (!(res = malloc(sizeof(t_list))))
		return (0);
	res->num = num;
	res->next = 0;
	res->prev = 0;
	return (res);
}

t_list			*ft_listdup(t_list *list)
{
	t_list		*res;

	if (!(res = malloc(sizeof(t_list))))
		return (0);
	res->num = list->num;
	res->prev = list->prev;
	res->next = list->next;
	return (res);
}

void			ft_listadd_front(t_list **list, t_list **new)
{
	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0 && (*new) != 0)
		(*list) = (*new);
	else
	{
		if ((*list)->prev)
			(*list)->prev->next = (*new);
		(*new)->prev = (*list)->prev;
		(*new)->next = *list;
		(*list)->prev = (*new);
	}
}

void			ft_listadd_back(t_list **list, t_list **new)
{
	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
		(*list) = (*new);
	else
	{
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
	((*list)->next)->prev = (*list)->prev;
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

#include <stdio.h>
int			main()
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;
	t_list	*list5;
	t_list	*list6;

	
	int			i = 1;
	list1 = ft_listnew(1);
	list2 = ft_listnew(2);
	list3 = ft_listnew(3);
	list4 = ft_listnew(4);
	list5 = ft_listnew(5);

	ft_listadd_back(&list3, &list4);
	ft_listadd_back(&list4, &list5);
	ft_listadd_front(&list3, &list2);
	ft_listadd_front(&list2, &list1);

	t_list *temp = list1;
	while (temp && i < 7)
	{
		printf("now  : %d | ", temp->num);
		if (temp->prev)
			printf("prev : %d | ", temp->prev->num);
		else
			printf("prev : %d | ", 0);

		if (temp->next)
			{
				printf("next : %d | ", temp->next->num);
			}
		else
			printf("next : %d | ", 0);
		printf("\n");
		temp = temp->next;
		i++;
	}
	printf("----------\n");
	temp = list1;
	ft_listexcpet(&list2);
	i = 0;
	while (temp && i < 7)
	{
		printf("now  : %d | ", temp->num);
		if (temp->prev)
			printf("prev : %d | ", temp->prev->num);
		else
			printf("prev : %d | ", 0);

		if (temp->next)
			{
				printf("next : %d | ", temp->next->num);
			}
		else
			printf("next : %d | ", 0);
			temp = temp->next;
		printf("\n");
		i++;
	}
}