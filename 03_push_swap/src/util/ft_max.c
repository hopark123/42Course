/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:03:06 by hopark            #+#    #+#             */
/*   Updated: 2021/04/30 16:17:29 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				ft_max(int n, ...)
{
	int				max;
	int				new;
	va_list			ap;

	max = INT_MIN;
	va_start(ap, n);
	while (n--)
	{
		new = va_arg(ap, int);
		max = max > new ? max : new;
	}
	va_end(ap);
	return (max);
}

int				ft_min(int n, ...)
{
	int				min;
	int				new;
	va_list 		ap;

	min = INT_MAX;
	va_start(ap, n);
	while (n--)
	{
		new = va_arg(ap, int);
		min = min < new ? min : new;
	}
	va_end(ap);
	return (min);
}