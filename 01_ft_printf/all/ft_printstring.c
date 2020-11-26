/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 02:34:10 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 20:03:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printstring(t_infor *infor, va_list ap)
{
	if (!infor->flag.left && infor->flag.zero)
		ft_printstring2(infor, ap, 0);
	ft_printstring2(infor, ap, ' ');
}

void		ft_printstring2(t_infor *infor, va_list ap, char c)
{
	int		strlen;
	char	*temp;
	char	*out;
	int		i;

	i = 0;
	temp = va_arg(ap, char *);
	strlen = (infor->precision >= 0 ? infor->precision : ft_strlen(temp));
	infor->size = ft_max(infor->width, strlen, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (!infor->flag.left)
		i = ft_max(strlen, infor->width, 0) - strlen;
	ft_memcpy(&out[i], temp, strlen);
}
