/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:45:48 by hopark            #+#    #+#             */
/*   Updated: 2021/05/05 18:09:11 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


void			ft_action(t_inf *inf, char *com)
{

	if (ft_strncmp(com, "sa", 2) || ft_strncmp(com, "ss", 2))
		ft_swap_tool(&(inf->a_h));
	if (ft_strncmp(com, "sb", 2) || ft_strncmp(com, "ss", 2))
		ft_swap_tool(&(inf->b_h));
	if (ft_strncmp(com, "pa", 2))
		ft_push_tool(&(inf->a_h), &(inf->b_h));
	if (ft_strncmp(com, "pb", 2))
		ft_push_tool(&(inf->b_h) , &(inf->a_h));
	if (ft_strncmp(com, "rra", 3) || ft_strncmp(com, "rrr", 3))
		ft_revrotate_tool(&inf->a_h, &inf->a_t);
	if (ft_strncmp(com, "rrb", 3) || ft_strncmp(com, "rrr", 3))
		ft_revrotate_tool(&inf->b_h, &inf->b_t);
	if (ft_strncmp(com, "ra", 2) || ft_strncmp(com, "rr", 2))
		ft_rotate_tool(&inf->a_h, &inf->a_t);
	if (ft_strncmp(com, "rb", 2) || ft_strncmp(com, "rr", 2))
		ft_rotate_tool(&inf->b_h, &inf->b_t);
	ft_htsetting(inf);
	cnt++;
	ft_show(inf, com);
	system("clear");
}

int				ft_swap_tool(t_list **type)
{
	int			temp;

	if (*type == 0 || (*type)->next == 0)
		return (0);
	temp = (*type)->num;
	(*type)->num = (*type)->next->num;
	(*type)->next->num = temp;
}

int				ft_push_tool(t_list **dest, t_list **src)
{
	t_list		*temp;

	if ((*src) == 0)
		return (0);
	temp = *src;
	ft_listexcpet(src);
	if ((*src) == (*src)->next)
		(*src) = 0;
	else
		(*src) = (*src)->next;
	ft_listadd_front(dest, &temp);
}

int				ft_rotate_tool(t_list **head, t_list **tail)
{
	(*head) = (*head)->next;
	(*tail) = (*tail)->next;
}

int				ft_revrotate_tool(t_list **head, t_list **tail)
{
	(*head) = (*head)->prev;
	(*tail) = (*tail)->prev;
}

int				ft_htsetting(t_inf *inf)
{
	if (inf->a_h)
	{
		inf->a_t = inf->a_h->prev;
		inf->a_t->next = inf->a_h;
		inf->a_h->prev = inf->a_t;
	}
	if (inf->b_h)
	{
		inf->b_t = inf->b_h->prev;
		inf->b_t->next = inf->b_h;
		inf->b_h->prev = inf->b_t;
	}

}