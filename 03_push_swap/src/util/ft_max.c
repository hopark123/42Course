/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:03:06 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 19:06:31 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int					ft_max(int n, ...)
{
	int				max;
	va_list 		ap;

	max = INT_MIN;
	
	va_start(ap, n);
	while (n--)
	{
		ap = va_arg(ap, int);
		max = max > ap ? max : ap;
	}
	return (max);
}

int					ft_max(int n, ...)
{
	int				min;
	va_list 		ap;

	min = INT_MIN;
	
	va_start(ap, n);
	while (n--)
	{
		ap = va_arg(ap, int);
		min = min < ap ? min : ap;
	}
	return (min);
}