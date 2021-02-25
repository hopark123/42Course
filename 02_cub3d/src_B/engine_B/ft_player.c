/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:45:12 by hopark            #+#    #+#             */
/*   Updated: 2021/02/21 17:53:53 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_player_move(t_game *g)
{
	float		speed;
	t_fvector	next_pt;
	
	speed = 0.1;
	if (g->move.x == 1)
	{
		next_pt.x = g->pos.x + speed * g->dir.x;
		next_pt.y = g->pos.y + speed * g->dir.y;

		if (!ft_check_fwall(g, next_pt))
			g->pos = next_pt;
	}
	else if (g->move.y == 1)
	{
		next_pt.x = g->pos.x - speed * g->dir.x;
		next_pt.y = g->pos.y - speed * g->dir.y;
		if (!ft_check_fwall(g, next_pt))
			g->pos = next_pt;
	}
	return (1);
}

int				ft_player_side(t_game *g)
{
	float		speed;
	t_fvector	next_pt;
	
	speed = 0.1;
	if (g->side.x == 1)
	{
		next_pt.x = g->pos.x + speed * g->plane.x;
		next_pt.y = g->pos.y + speed * g->plane.y;

		if (!ft_check_fwall(g, next_pt))
			g->pos = next_pt;
	}
	else if (g->side.y == 1)
	{
		next_pt.x = g->pos.x - speed * g->plane.x;
		next_pt.y = g->pos.y - speed * g->plane.y;
		if (!ft_check_fwall(g, next_pt))
			g->pos = next_pt;
	}
	return (1);
}
int				ft_player_turn(t_game *g)
{
	if (g->turn.x == 1)
		g->dir = ft_rotation(g->dir, M_PI / 30);
	else if (g->turn.y == 1)
		g->dir = ft_rotation(g->dir, -M_PI / 30);
	g->plane = ft_rotation(g->dir, M_PI / 2);
	return (1);
}
