/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_infor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:19:08 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 21:42:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_parse.h"

void		ft_init_flag(t_flag *flag)
{
	flag->left = 0;
	flag->plus = 0;
	flag->blank = 0;
	flag->zero = 0;
	flag->hash = 0;
}

t_infor		*ft_init_infor(t_infor *infor)
{
	t_infor		*result;

	if (!(result = malloc(sizeof(t_infor))))
		return (0);
	ft_init_flag(&(result->flag));
	result->nega = 0;
	result->len = -1;
	result->width = -1;
	result->precision = -1;
	result->type = 0;
	result->content = 0;
	infor = result;
	return (result);
}
