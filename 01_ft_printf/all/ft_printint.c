/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 20:58:34 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printint(t_infor *infor, va_list ap)
{
	if (!infor->flag.left && infor->precision < 0 && infor->flag.zero)
		ft_printint2(infor, ap, 0);
	else
		ft_printint2(infor, ap, ' ');
}

void		ft_printint2(t_infor *infor, va_list ap, char c)
{
	int		number;

	if ((number = va_arg(ap, int)) < 0)
	{
		number *= -1;
		infor->nega = 1;
	}
	infor->len = ft_int_len(number);
	infor->size = ft_max(infor->len, infor->width, infor->precision);
	if (infor->size > infor->len && infor->size > infor->precision)
	{
		if (infor->flag.left)
			ft_int_nz_wl(infor, number, c);
		else
			ft_int_nz_wr(infor, number, c);
	}
	else if (infor->flag.plus || infor->flag.blank || infor->nega)
		ft_int_nz_sign(infor, number, c);
	else
		ft_int_nz_nsign(infor, number, c);
}
