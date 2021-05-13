/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:59:39 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 20:41:53 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two_a(t_inf *inf)
{
	if (inf->a_h->num > inf->a_h->next->num)
		ft_action(inf, "sa");
	inf->a_h->chunk = -5;
	inf->a_h->next->chunk = -5;
}

void	ft_two_b(t_inf *inf)
{
	if (inf->b_h->num < inf->b_h->next->num)
		ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "pa");
	inf->a_h->chunk = -5;
	inf->a_h->next->chunk = -5;
}
