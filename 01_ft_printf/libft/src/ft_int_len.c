/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:27:59 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 03:34:53 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_int_len(long long n)
{
	int			len;
	long long	n2;

	len = 0;
	n2 = (long long)n;
	if (n2 < 0)
	{
		len++;
		n2 *= -1;
	}
	while (n2 >= 10)
	{
		len++;
		n2 /= 10;
	}
	if (n == LLONG_MIN)
		return (18);
	return (++len);
}
