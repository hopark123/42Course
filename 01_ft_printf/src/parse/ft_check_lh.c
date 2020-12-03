/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 01:26:59 by hopark            #+#    #+#             */
/*   Updated: 2020/12/04 00:07:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_parse.h"

void			ft_check_lh(char **format, t_infor *infor)
{
	if (**format == 'h')
		infor->hcount++;
	else if (**format == 'l')
		infor->lcount++;
	(*format)++;
	return ;
}
