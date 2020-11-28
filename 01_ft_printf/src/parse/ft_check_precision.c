/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:21:03 by hopark            #+#    #+#             */
/*   Updated: 2020/11/29 04:52:17 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_parse.h"

void			ft_check_precision(char **format, t_infor *infor, va_list ap)
{
	int		temp;

	(*format)++;
	temp = 0;
	if (**format == '*')
	{
		if ((infor->precision = va_arg(ap, int)) < 0)
		{
			infor->precision = -1;
		}
		(*format)++;
		return ;
	}
	while (ft_strchr("0123456789", **format))
	{
		temp *= 10;
		temp += **format - '0';
		(*format)++;
	}
	infor->precision = temp;
}
