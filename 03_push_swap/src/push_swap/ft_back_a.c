/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:56:22 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 16:28:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_back_a(t_inf *inf, float chunk)
{
	float			temp;

	temp = inf->a_t->chunk;
	if (!inf->b_h)
		return ;
	if (inf->a_h->chunk != -5 && !ft_is_ascending(inf->a_h) \
			&& inf->a_t->chunk > inf->b_h->chunk)
	{
		while (1)
		{
			ft_action(inf, "rra");
			inf->a_h->chunk = temp;
			if (temp != inf->a_t->chunk)
				return ;
		}
	}
}
