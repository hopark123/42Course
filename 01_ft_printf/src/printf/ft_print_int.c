/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 03:17:54 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_int(t_infor *infor, va_list ap)
{
	if (!infor->flag.left && infor->precision < 0 && infor->flag.zero)
		ft_printf_int(infor, ap, 0);
	else
		ft_printf_int(infor, ap, ' ');
}

long long	ft_int_size(t_infor *infor, va_list ap)
{
	long long	number;

	if (infor->lcount > 0 && infor->lcount % 2 == 0)
		return (number = va_arg(ap, long long));
	else if (infor->lcount > 0 && infor->lcount % 2 == 1)
		return (number = va_arg(ap, long));
	else if (infor->hcount > 0 && infor->hcount % 2 == 1)
		return (number = (short int)va_arg(ap, int));
	else if (infor->hcount > 0 && infor->hcount % 2 == 0)
		return (number = (char)va_arg(ap, int));
	else
		return (number = va_arg(ap, int));
}

void		ft_printf_int(t_infor *infor, va_list ap, char c)
{
	long long	number;

	if ((number = ft_int_size(infor, ap)) < 0)
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
