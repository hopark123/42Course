/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2020/12/17 16:40:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_int(t_infor *infor, va_list ap)
{
	long long	number;

	if ((number = ft_int_size(infor, ap)) < 0)
	{
		number *= -1;
		infor->nega = 1;
	}
	infor->len = ft_int_len(number);
	if (number == 0 && infor->precision == 0)
	{
		ft_int_null(infor);
		return ;
	}
	infor->content = ft_itoa(number);
	infor->size = ft_max(infor->len, infor->width, infor->precision);
	if (!infor->flag.left && infor->flag.zero)
	{
		if (infor->size > infor->len && infor->size > infor->precision)
			ft_int_z_w(infor);
		else
			ft_int_z(infor);
	}
	else
		ft_printf_int(infor);
}

long long		ft_int_size(t_infor *infor, va_list ap)
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

void			ft_int_null(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	j = 0;
	i = 0;
	infor->len = 0;
	if (infor->nega || infor->flag.plus || infor->flag.blank)
		infor->len = 1;
	infor->size = ft_max(infor->len, infor->width, infor->precision);
	out = ft_calloc_c(infor->size + 1, sizeof(char), 0);
	if (!infor->flag.left)
		while (j++ < infor->width - infor->len)
			out[i++] = ' ';
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	j = 0;
	while (j++ <= infor->width - infor->len)
		out[i++] = ' ';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	infor->content = out;
}

void			ft_int_z(t_infor *infor)
{
	char		*out;
	int			i;

	i = 0;
	infor->size++;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	else
		infor->size--;
	while (i < infor->size - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void			ft_int_z_w(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), '0');
	if (infor->inprec == 1)
		while (i < infor->width - ft_max(infor->precision, infor->len, 0) - 1)
			out[i++] = ' ';
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	if (infor->inprec == 1)
		while (i < infor->width - ft_max(infor->precision, infor->len, 0))
			out[i++] = ' ';
	while (i < infor->width - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}
