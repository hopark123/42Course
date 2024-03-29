/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_infor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:19:08 by hopark            #+#    #+#             */
/*   Updated: 2020/12/11 17:23:17 by hopark           ###   ########.fr       */
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
	result->len = 0;
	result->width = 0;
	result->size = 0;
	result->precision = 1;
	result->inprec = 0;
	result->type = 0;
	result->hcount = 0;
	result->lcount = 0;
	result->content = 0;
	infor = result;
	return (result);
}
