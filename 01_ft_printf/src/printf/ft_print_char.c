/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:48:06 by hopark            #+#    #+#             */
/*   Updated: 2020/11/29 04:05:27 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_char(t_infor *infor, va_list ap)
{
	char c;

	infor->content = ft_calloc_c(1, sizeof(char), ' ');
	c = (infor->type == 'c' ? (char)va_arg(ap, int) : infor->type);
	infor->content[0] = c;
	if (!infor->content[0])
	{
		ft_char_null(infor);
		return ;
	}
	infor->size = ft_max(infor->width, 1, 0);
	if (!infor->flag.left && infor->precision < 0 && infor->flag.zero)
		ft_char_z(infor);
	else
		ft_printf_char(infor);
}

void		ft_char_z(t_infor *infor)
{
	char		*out;
	int			i;

	i = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	while (i < infor->width - infor->len - 1)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, 1);
	free(infor->content);
	infor->content = out;
}

void		ft_char_null(t_infor *infor)
{
	char		*out;
	int			i;

	infor->len = 1;
	infor->size = ft_max(infor->len, infor->width, infor->precision);
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->flag.left)
	{
		i = 0;
		out[i] = 0;
		i++;
	}
	else
		i = ft_max(1, infor->width, 0) - ft_max(infor->precision, 1, 0);
	while (i < infor->width - 1)
		out[i++] = ' ';
	free(infor->content);
	if (!infor->flag.left)
		out[i] = 0;
	infor->content = out;
}

void		ft_printf_char(t_infor *infor)
{
	char	*out;
	int		i;

	i = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (!infor->flag.left)
		i = infor->size - 1;
	ft_memcpy(&out[i], infor->content, 1);
	free(infor->content);
	infor->content = out;
}
