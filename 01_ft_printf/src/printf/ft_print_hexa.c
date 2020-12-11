/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:09:41 by hopark            #+#    #+#             */
/*   Updated: 2020/12/11 18:14:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_print_hexa(t_infor *infor, va_list ap)
{
	unsigned long long number;

	number = ft_hexa_size(infor, ap);
	if (number == 0 && infor->precision == 0)
	{
		ft_hexa_null(infor);
		return ;
	}
	if ((infor->inprec == 2 && number == 0) || number == 0)
		infor->flag.hash = 0;
	infor->len = ft_hexa_len("0123456789abcdef", number);
	infor->content = ft_calloc_c(infor->len + 1, sizeof(char), ' ');
	infor->size = ft_max(infor->len, infor->precision, 0);
	if (infor->type == 'X')
	{
		infor->content = ft_hexa_itoa(infor, "0123456789ABCDEF", number, 1);
		ft_printf_hexa(infor);
	}
	else
	{
		infor->content = ft_hexa_itoa(infor, "0123456789abcdef", number, 1);
		ft_printf_hexa(infor);
	}
}

unsigned long long		ft_hexa_size(t_infor *infor, va_list ap)
{
	unsigned long long number;

	if (infor->type == 'p')
		return (number = (unsigned long long)va_arg(ap, void *));
	else if ((infor->lcount > 0 && infor->lcount % 2 == 0))
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

void					ft_hexa_null(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	infor->len = (infor->type == 'p' ? 2 : 0);
	infor->size = ft_max(infor->len, infor->width, infor->precision);
	out = ft_calloc_c(infor->size + 1, sizeof(char), 0);
	i = 0;
	j = infor->len == 2 ? 2 : 0;
	if (!infor->flag.left)
		while (j++ < infor->width - infor->precision)
			out[i++] = ' ';
	if (infor->type == 'p')
	{
		out[i++] = '0';
		out[i++] = (infor->type == 'X' ? 'X' : 'x');
	}
	j = infor->len == 2 ? 2 : 0;
	while (j++ <= infor->width - infor->len)
		out[i++] = ' ';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	infor->content = out;
}

void					ft_hexa_hz(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	infor->size = ft_max(infor->size, infor->width, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), '0');
	if (infor->inprec == 2)
		infor->precision = infor->width;
	if (infor->inprec == 1)
		while (j++ < infor->size - ft_max(infor->precision, infor->len, 0) - 2)
			out[i++] = ' ';
	out[i++] = '0';
	out[i++] = (infor->type == 'X' ? 'X' : 'x');
	if (infor->inprec != 2)
		while (i + j < infor->width - ft_max(infor->precision, infor->len, 0))
			out[i++] = '0';
	while (i < infor->size - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void					ft_hexa_z(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (infor->width > infor->size)
		infor->size = infor->width;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->inprec == 1)
	{
		while (i < infor->width - ft_max(infor->precision, infor->len, 0))
			out[i++] = ' ';
		while (j++ < ft_max(infor->precision, infor->len, 0) - infor->len)
			out[i++] = '0';
	}
	else
		while (i < infor->width - infor->len)
			out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}
