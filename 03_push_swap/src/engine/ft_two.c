/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:59:39 by hopark            #+#    #+#             */
/*   Updated: 2021/04/30 13:59:35 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			ft_two_a(t_inf *inf)
{
	printf("two_a\n");

	if (inf->a_h->num > inf->a_h->next->num)
		ft_action(inf, "sa");
}
void			ft_two_b(t_inf *inf)
{
	printf("two_b\n");
	if (inf->b_h->num < inf->b_h->next->num)
		ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "pa");
}