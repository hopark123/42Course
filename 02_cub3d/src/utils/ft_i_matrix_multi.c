/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_matrix_multi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:37:58 by hopark            #+#    #+#             */
/*   Updated: 2021/02/13 14:43:33 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvector			ft_i_matrix_multi(t_fvector m1, t_fvector m2, t_fvector v)
{
	t_fvector	res;
	float		invert;

	invert = 1.0 / (m1.x * m2.y - m1.y * m2.x);
	res.x = invert * (m2.y * v.x - m2.x * v.y);
	res.y = invert * (-m1.y * v.x + m1.x * v.y);
	return (res);
}
