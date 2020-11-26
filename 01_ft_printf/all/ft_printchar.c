/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:48:06 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 20:03:36 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printchar(t_infor *infor, va_list ap)
{
	if (!infor->flag.left && !infor->precision && infor->flag.zero)
		ft_printchar2(infor, ap, 0);
	ft_printchar2(infor, ap, ' ');
}

void		ft_printchar2(t_infor *infor, va_list ap, char c)
{
	char	*out;
	int		i;

	i = 0;
	infor->size = infor->precision ? 1 : ft_max(infor->width, 1, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (!infor->flag.left)
		i = infor->size - 1;
	out[i] = (char)va_arg(ap, int);
	infor->content = out;
}
