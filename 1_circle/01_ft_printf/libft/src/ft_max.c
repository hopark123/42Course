/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:25 by hopark            #+#    #+#             */
/*   Updated: 2020/12/11 18:05:19 by hopark           ###   ########.fr       */
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
