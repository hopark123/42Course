/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:37:01 by hopark            #+#    #+#             */
/*   Updated: 2021/02/21 16:03:12 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_player_init(t_game *g, int i, int j, char c)
{
	g->pos.x = j + 0.5;
	g->pos.y = i + 0.5;
	if (c == 'N')
	{
		g->dir.x = 0;
		g->dir.y = -1;
	}
	else if(c == 'S')
	{
		g->dir.x = 0;
		g->dir.y = 1;

	}
	else if(c =='W')
	{
		g->dir.x = -1;
		g->dir.y = 0;
	}
	else if(c == 'E')
	{
		g->dir.x = 1;
		g->dir.y = 0;
	}
	g->plane = ft_rotation(g->dir, M_PI / 2);
}