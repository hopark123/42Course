/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:21:30 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 02:57:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_make_content(t_infor *infor, va_list ap)
{
	if (infor->type == 'c')
		ft_print_char(infor, ap);
	else if (infor->type == 's')
		ft_print_string(infor, ap);
	// else if (infor->type == 'p')
	// 	ft_printpoint(infor, ap);
	else if (infor->type == 'd' || infor->type == 'i')
		ft_print_int(infor, ap);
	else if (infor->type == 'u')
		ft_print_uint(infor, ap);
	// else if (infor->type == 'x' || infor->type == 'X')
	// 	ft_printhexa(infor, ap);
	// else if (infor->type == 'n')
	// 	ft_printn(infor, ap);
	// else if (infor->type == 'f')
	// 	ft_printfloat(infor, ap);
	// else if (infor->type == 'g')
	// 	ft_printg(infor, ap);
	// else if (infor->type == 'e')
	// 	ft_printe(infor, ap);
	else
		ft_print_char(infor, ap);
}
