/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:36:57 by hopark            #+#    #+#             */
/*   Updated: 2021/02/10 16:44:10 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvector			ft_rotation(t_fvector src, float angle)
{
	t_fvector dest;

	dest.x = cos(angle) * src.x - sin(angle) * src.y;
	dest.y = sin(angle) * src.x + cos(angle) * src.y;
	return (dest);
}
