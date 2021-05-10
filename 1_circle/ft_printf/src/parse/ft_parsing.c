/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:19:57 by hopark            #+#    #+#             */
/*   Updated: 2020/12/11 17:22:59 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parsing(char **format, va_list ap, t_infor *infor)
{
	while (**format)
	{
		if (ft_strchr("-+ 0#", **format))
			ft_check_flag(format, infor);
		else if (ft_strchr("123456789*", **format))
			ft_check_width(format, infor, ap);
		else if (ft_strchr(".", **format))
			ft_check_precision(format, infor, ap);
		else if (ft_strchr("lh", **format))
			ft_check_lh(format, infor);
		else
		{
			infor->type = **format;
			ft_make_content(infor, ap);
			(*format)++;
			return (infor->size);
		}
	}
	return (-1);
}
