/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:38:25 by hopark            #+#    #+#             */
/*   Updated: 2021/02/10 16:44:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float			vector_len(t_fvector v1, t_fvector v2)
{
	float		tempx;
	float		tempy;

	if (v2.x == 0 && v2.y == 0)
	{
		tempx = sqrt(v1.x * v1.x + v2.y * v2.y);
		return (tempx);
	}
	tempx = fabs(v1.x - v2.x) * fabs(v1.x - v2.x);
	tempy = fabs(v1.y - v2.y) * fabs(v1.y - v2.y);
	tempx = sqrt(tempx + tempy);
	return (tempx);
}
