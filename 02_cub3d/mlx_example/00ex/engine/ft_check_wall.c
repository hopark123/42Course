/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:39:54 by hopark            #+#    #+#             */
/*   Updated: 2021/02/09 22:29:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_check_fwall(t_game *g, t_fvector pt)
{
	if (pt.x < 0 || pt.x > g->map.size.x || pt.y < 0 || pt.y > g->map.size.y)
		return (1);
	return (map[(int)(pt.y * g->map.size.x) + (int)pt.x] != 0);
}

int				ft_check_iwall(t_game *g, t_ivector pt)
{
	if (pt.x < 0 || pt.x > g->map.size.x || pt.y < 0 || pt.y > g->map.size.y)
		return (1);
	return (map[(int)(pt.y * g->map.size.x) + pt.x] != 0);
}
