/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:45:48 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 20:07:17 by hopark           ###   ########.fr       */
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
		ft_push_tool(&(inf->a_h), &(inf->a_h));
	if (ft_strncmp(com, "pb", 2))
		ft_push_tool(&(inf->b_h) , &(inf->a_h));
	if (ft_strncmp(com, "rra", 3) || ft_strncmp(com, "rrr", 3))
		ft_revrotate_tool(inf, com);
	if (ft_strncmp(com, "rrb", 3) || ft_strncmp(com, "rrr", 3))
		ft_revrotate_tool(inf, com);
	if (ft_strncmp(com, "ra", 2) || ft_strncmp(com, "rr", 2))
		ft_rotate_tool(inf , com);
	if (ft_strncmp(com, "rb", 2) || ft_strncmp(com, "rr", 2))
		ft_rotate_tool(inf, com);
	write(1,"O",1);
	ft_htsetting(inf);
	write(1,"P",1);
	ft_show(inf, com);
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
	t_list		**temp;

	if ((*src) == 0)
		return (0);
	temp = src;
	ft_listexcpet(src);
	(*src) = (*src)->next;
	ft_listadd_back(dest, temp);
}

int				ft_rotate_tool(t_inf *inf, char *com)
{
	if (ft_strncmp(com, "ra", 2) || ft_strncmp(com, "rr", 2) && inf->a_h)
		(inf->a_h) = inf->a_h->next;
	if (ft_strncmp(com, "rb", 2) || ft_strncmp(com, "rr", 2) && inf->b_h)
		(inf->b_h) = inf->b_h->next;
}

int				ft_revrotate_tool(t_inf *inf, char *com)
{
	if (ft_strncmp(com, "rra", 3) || ft_strncmp(com, "rrr", 3)) 
		(inf->a_h) = inf->a_h->prev;
	if (ft_strncmp(com, "rrb", 3) || ft_strncmp(com, "rrr", 3))
		(inf->b_h) = inf->b_h->prev;
}

int				ft_htsetting(t_inf *inf)
{
	write(1,"T",1);
	if (inf->a_h)
	{
		inf->a_h->next = inf->a_t;
		inf->a_t->prev = inf->a_h;
	}

	if (inf->b_h)
	{
	write(1,"T",1);
		inf->b_h->next = inf->b_t;
	write(1,"T",1);
		inf->b_t->prev = inf->b_h;
	}

}