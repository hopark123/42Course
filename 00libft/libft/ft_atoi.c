/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:10:23 by hopark            #+#    #+#             */
/*   Updated: 2020/10/09 01:02:20 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *nptr)
{
	int				num;
	int				sign;
	int				i;
	int				cnt;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	cnt = i;
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	if (i - cnt >= 20)
		return (sign > 0 ? -1 : 0);
	return (num * sign);
}
