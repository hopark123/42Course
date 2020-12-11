/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2020/12/11 18:09:07 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_print_uint(t_infor *infor, va_list ap)
{
	unsigned long long	number;

	number = ft_uint_size(infor, ap);
	if (number == 0 && infor->precision == 0)
	{
		ft_int_null(infor);
		return ;
	}
	infor->len = ft_uint_len(number);
	infor->content = ft_uitoa(number);
	infor->size = ft_max(infor->len, infor->width, infor->precision);
	if (!infor->flag.left && infor->flag.zero)
	{
		if (infor->size > infor->len && infor->size > infor->precision)
		{
			ft_int_z_w(infor);
		}
		else
			ft_int_z(infor);
	}
	else
		ft_printf_int(infor);
}

unsigned long long		ft_uint_size(t_infor *infor, va_list ap)
{
	unsigned long long	number;

	if (infor->lcount > 0 && infor->lcount % 2 == 0)
		return (number = (unsigned long long)va_arg(ap, long long));
	else if (infor->lcount > 0 && infor->lcount % 2 == 1)
		return (number = va_arg(ap, unsigned long));
	else if (infor->hcount > 0 && infor->hcount % 2 == 1)
		return (number = (unsigned short int)va_arg(ap, int));
	else if (infor->hcount > 0 && infor->hcount % 2 == 0)
		return (number = (unsigned char)va_arg(ap, int));
	else
		return (number = (unsigned int)va_arg(ap, unsigned int));
}
