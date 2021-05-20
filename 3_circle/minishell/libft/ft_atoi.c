/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:47:21 by suhong            #+#    #+#             */
/*   Updated: 2021/05/06 17:46:29 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		digit;
	int		sign;
	int		tmp;
	char	*p;

	sign = 1;
	tmp = 0;
	digit = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	p = (char *)nptr;
	while (p[digit] != '\0' && (p[digit] >= '0' && p[digit] <= '9'))
		tmp = (tmp * 10) + (p[digit++] - '0');
	if (digit >= 19)
		return (tmp = sign & 0x10000000);
	return (tmp * sign);
}
