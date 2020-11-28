/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2020/11/29 02:30:42 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



unsigned long long	ft_uint_size(t_infor *infor, va_list ap)
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

void		ft_print_uint(t_infor *infor, va_list ap)
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
	if (!infor->flag.left && infor->precision < 0 && infor->flag.zero)
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

void		ft_printf_uint(t_infor *infor)
{
	if (infor->size > infor->len && infor->size > infor->precision)
	{
		if (infor->flag.left)
			ft_uint_nz_wl(infor);
		else
			ft_uint_nz_wr(infor);
	}
	else if (infor->flag.plus || infor->flag.blank || infor->nega)
		ft_uint_nz_sign(infor);
	else
		ft_uint_nz_nsign(infor);
}

void		ft_uint_z_w(t_infor *infor)
{
	char		*out;
	int			i;

	i = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else
		out[i++] = '0';
	while (i < infor->width - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void		ft_uint_z(t_infor *infor)
{
	char		*out;
	int			i;

	i = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	while (i < infor->width - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}
