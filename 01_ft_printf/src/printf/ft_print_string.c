/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 02:34:10 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 19:51:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_string(t_infor *infor, va_list ap)
{
	if (!infor->flag.left && infor->flag.zero)
		ft_printf_string(infor, ap, '0');
	else
		ft_printf_string(infor, ap, ' ');
}

void		ft_printf_string(t_infor *infor, va_list ap, char c)
{
	int		strlen;
	char	*temp;
	char	*out;
	int		i;
	i = 0;
	temp = va_arg(ap, char *);
	if (temp == 0)
	{
		temp = ft_put_null(temp);
		infor->width = 6;
		infor->precision = ft_min(infor->precision, 6, 6);
	}
	if (infor->precision >= 0)
		strlen = ft_min(ft_strlen(temp), infor->precision, INT_MAX);
	else
		strlen = ft_strlen(temp);
	infor->size = ft_max(infor->precision, strlen, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (!infor->flag.left)
		i = infor->size - strlen;
	ft_memcpy(&out[i], temp, strlen);
	infor->content = out;
}

char		*ft_put_null(char *temp)
{
	char *nullstring;

	nullstring = ft_calloc_c(7, sizeof(char), 0);
	nullstring[0] = '(';
	nullstring[1] = 'n';
	nullstring[2] = 'u';
	nullstring[3] = 'l';
	nullstring[4] = 'l';
	nullstring[5] = ')';
	free(temp);
	return (nullstring);
}
