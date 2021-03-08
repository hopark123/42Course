/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:37:01 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 15:48:58 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_player_init(t_game *g, int i, int j, char c)
{
	if (g->inpos == -1)
		ft_exit_msg(g, "map error");
	g->pos.x = j;
	g->pos.y = i;
	g->dir.x = 1;
	g->dir.y = 0;
	if (c == 'N')
	{
		g->dir.x = 0;
		g->dir.y = -1;
	}
	else if (c == 'S')
	{
		g->dir.x = 0;
		g->dir.y = 1;
	}
	else if (c == 'W')
	{
		g->dir.x = -1;
		g->dir.y = 0;
	}
	g->plane = ft_rotation(g->dir, M_PI / 2);
	g->inpos = -1;
}
