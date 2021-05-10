/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:50:23 by hopark            #+#    #+#             */
/*   Updated: 2020/12/03 23:28:30 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_int(t_infor *infor)
{
	if (infor->size > infor->len && infor->size > infor->precision)
	{
		if (infor->flag.left)
			ft_int_nz_wl(infor);
		else
			ft_int_nz_wr(infor);
	}
	else if (infor->flag.plus || infor->flag.blank || infor->nega)
		ft_int_nz_sign(infor);
	else
		ft_int_nz_nsign(infor);
}

void		ft_int_nz_wl(t_infor *infor)
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
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void		ft_int_nz_wr(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = infor->width - ft_max(infor->precision, infor->len, 0) - 1;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	else
		i++;
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, ft_strlen(infor->content));
	free(infor->content);
	infor->content = out;
}

void		ft_int_nz_nsign(t_infor *infor)
{
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), ' ');
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, infor->size);
	free(infor->content);
	infor->content = out;
}

void		ft_int_nz_sign(t_infor *infor)
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
	else if (infor->flag.blank)
		out[i++] = ' ';
	else
		i++;
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], infor->content, infor->size);
	free(infor->content);
	infor->content = out;
}
