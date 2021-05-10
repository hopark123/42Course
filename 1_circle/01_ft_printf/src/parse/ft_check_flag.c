/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:20:17 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 18:53:50 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_parse.h"

void			ft_check_flag(char **format, t_infor *infor)
{
	if (**format == '-')
		infor->flag.left = 1;
	else if (**format == '+')
		infor->flag.plus = 1;
	else if (**format == ' ')
		infor->flag.blank = 1;
	else if (**format == '0')
		infor->flag.zero = 1;
	else if (**format == '#')
		infor->flag.hash = 1;
	(*format)++;
	return ;
}
