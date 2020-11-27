/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:30:07 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 18:13:11 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hexa_itoa(t_infor *infor, char *base,\
						unsigned long long num, int i)
{
	if (num > 16)
		ft_hexa_itoa(infor, base, num / 16, i + 1);
	infor->content[infor->len - i] = base[num % 16];
	return (infor->content);
}

int			ft_hexa_len(char *base, unsigned long long num)
{
	int		numlen;

	numlen = 0;
	while (num >= (unsigned long long)ft_strlen(base))
	{
		numlen++;
		num /= ft_strlen(base);
	}
	if (num == ULLONG_MAX)
		return (8);
	return (++numlen);
}
