/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htsetting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:05:09 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 16:23:21 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_htsetting(t_inf *inf)
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
