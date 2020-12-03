/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:25 by hopark            #+#    #+#             */
/*   Updated: 2020/11/29 02:33:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_max(long long a, long long b, long long c)
{
	long long		temp;

	temp = a >= b ? a : b;
	return (temp >= c ? temp : c);
}

long long		ft_min(long long a, long long b, long long c)
{
	long long		temp;

	temp = a <= b ? a : b;
	return (temp <= c ? temp : c);
}
