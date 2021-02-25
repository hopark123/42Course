/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:39:54 by hopark            #+#    #+#             */
/*   Updated: 2021/02/20 12:41:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int				ft_check_fwall(t_game *g, t_fvector pt)
{
	if (pt.x < 0 || pt.x > g->map.size.x || pt.y < 0 || pt.y > g->map.size.y)
		return (1);
	return (g->map.m[(int)pt.y][(int)pt.x] == '1');
}

int				ft_check_iwall(t_game *g, t_ivector pt)
{
	if (pt.x < 0 || pt.x > g->map.size.x || pt.y < 0 || pt.y > g->map.size.y)
		return (1);
	return (g->map.m[pt.y][pt.x] == '1');
}
