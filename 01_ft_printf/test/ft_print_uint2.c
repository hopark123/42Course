/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:50:23 by hopark            #+#    #+#             */
/*   Updated: 2020/11/29 02:17:34 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_uint_nz_wl(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len - 1)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void		ft_uint_nz_wr(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = infor->width - ft_umax(infor->precision, infor->len, 0) - 1;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len - 1)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void		ft_uint_nz_nsign(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;

	out = ft_calloc_c(infor->size, sizeof(char), ' ');
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, infor->size);
	free(infor->content);
	infor->content = out;
}

void		ft_uint_nz_sign(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	infor->size++;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}
