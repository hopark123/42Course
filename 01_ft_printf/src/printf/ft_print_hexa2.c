/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:06:21 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 18:32:38 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hexa_hl(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	infor->size = ft_max(infor->size, infor->width, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	out[i++] = '0';
	out[i++] = (infor->type == 'X' ? 'X' : 'x');
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void		ft_hexa_hr(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (infor->width > infor->size)
	{
		i = infor->width - infor->size;
		infor->size = infor->width;
	}
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	out[i++] = '0';
	out[i++] = (infor->type == 'X' ? 'X' : 'x');
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void		ft_hexa_nhl(t_infor *infor)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	infor->size = ft_max(infor->size, infor->width, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	while (j++ < infor->precision - infor->len - 1)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(temp));
	free(infor->content);
	infor->content = out;
}

void		ft_hexa_nhr(t_infor *infor)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (infor->width > infor->size)
	{
		i = infor->width - infor->size;
		infor->size = infor->width;
	}
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(temp));
	free(infor->content);
	infor->content = out;
}