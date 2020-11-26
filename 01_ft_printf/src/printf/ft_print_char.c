/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:48:06 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 02:52:14 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_char(t_infor *infor, va_list ap)
{
	if (!infor->flag.left && !infor->precision && infor->flag.zero)
		ft_printf_char(infor, ap, '0');
	else
		ft_printf_char(infor, ap, ' ');
}

void		ft_printf_char(t_infor *infor, va_list ap, char c)
{
	char	*out;
	int		i;

	i = 0;
	infor->size = ft_max(infor->width, 1, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (!infor->flag.left)
		i = infor->size - 1;
	out[i] = (char)va_arg(ap, int);
	infor->content = out;
}
