/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:20:46 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 18:53:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_parse.h"

void			ft_check_width(char **format, t_infor *infor, va_list ap)
{
	int		temp;

	temp = 0;
	if (**format == '*')
	{
		if ((infor->width = va_arg(ap, int)) <= 0)
		{
			infor->flag.left = 1;
			infor->width *= -1;
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
	infor->width = temp;
}
