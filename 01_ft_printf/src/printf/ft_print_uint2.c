/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:50:23 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 03:14:32 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_uint_nz_wl(t_infor *infor, unsigned long long number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	temp = ft_uitoa(number);
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len - 1)
		out[i++] = '0';
	ft_memcpy(&out[i], temp, ft_strlen(temp));
	infor->content = out;
	free(temp);
}

void		ft_uint_nz_wr(t_infor *infor, unsigned long long number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = infor->width - ft_umax(infor->precision, infor->len, 0) - 1;
	j = 0;

	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	temp = ft_uitoa(number);
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len - 1)
		out[i++] = '0';
	ft_memcpy(&out[i], temp, ft_strlen(temp));
	infor->content = out;
	free(temp);
}

void		ft_uint_nz_nsign(t_infor *infor, unsigned long long number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;

	temp = ft_uitoa(number);
	out = ft_calloc_c(infor->size, sizeof(char), c);
	if (number == 0 && infor->width == 0 && infor->precision == 0)
		infor->size = 0;
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';

	ft_memcpy(&out[i], temp, infor->size);
	infor->content = out;
	free(temp);
}

void		ft_uint_nz_sign(t_infor *infor, unsigned long long number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	infor->size++;
	temp = ft_uitoa(number);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], temp, ft_strlen(temp));
	infor->content = out;
	free(temp);
}
