/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:09:41 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 18:40:23 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_hexa(t_infor *infor, va_list ap)
{
	if (infor->type == 'X')
		ft_printf_hexa(infor, ap, "0123456789ABCDEF");
	else if (infor->type == 'x')
		ft_printf_hexa(infor, ap, "0123456789abcdef");
	else
		ft_printf_hexa(infor, ap, "0123456789abcdef");
}

unsigned long long		ft_hexa_size(t_infor *infor, va_list ap)
{
	unsigned long long number;

	if ((infor->lcount > 0 && infor->lcount % 2 == 0) || infor->type == 'p')
		return (number = va_arg(ap, unsigned long long));
	else if (infor->lcount > 0 && infor->lcount % 2 == 1)
		return (number = va_arg(ap, unsigned long));
	else if (infor->hcount > 0 && infor->hcount % 2 == 1)
		return (number = (unsigned short int)va_arg(ap, unsigned int));
	else if (infor->hcount > 0 && infor->hcount % 2 == 0)
		return (number = (unsigned char)va_arg(ap, unsigned int));
	else
		return (number = va_arg(ap, unsigned int));
}

void			ft_printf_hexa(t_infor *infor, va_list ap, char *base)
{
	unsigned long long number;

	number = ft_hexa_size(infor, ap);

	infor->len = ft_hexa_len(base, number);
	infor->size = ft_max(infor->len, infor->precision, 0);
	infor->content = ft_calloc_c(infor->len + 1, sizeof(char), ' ');
	infor->content = ft_hexa_itoa(infor, base, number, 1);
	if (infor->flag.hash == 1 || infor->type == 'p')
	{
		infor->size += 2;
		if (infor->flag.left)
			ft_hexa_hl(infor);
		else
			ft_hexa_hr(infor);
	}
	else
	{
		if (infor->flag.left)
			ft_hexa_nhl(infor);
		else
			ft_hexa_nhr(infor);
	}
}

