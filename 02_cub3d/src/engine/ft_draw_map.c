/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:46:42 by hopark            #+#    #+#             */
/*   Updated: 2021/02/20 14:19:44 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_map_draw2(t_game *g)
{
	int i;
	int j;

	i = 0;
	while (i <= g->map.size.y * TILESIZE)
	{
		j = 0;
		while (j <= g->map.size.x * TILESIZE)
		{
			if (i % TILESIZE == 0 || j % TILESIZE == 0)
				g->img.data[i * g->size.x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void			ft_map_draw(t_game *g)
{
	int			i;
	int			j;
	t_ivector	pt;

	i = 0;
	while (i < g->map.size.y)
	{
		j = 0;
		while (j < g->map.size.x)
		{
			pt.x = j;
			pt.y = i;
			if (g->map.m[i][j] == '1')
				ft_draw_square(g, pt, TILESIZE, 0x88FF70);
			else
				ft_draw_square(g, pt, TILESIZE, 0x000000);
			j++;
		}
		i++;
	}
	ft_map_draw2(g);
}

void			ft_draw_floor(t_game *g, unsigned int color)
{
	int			i;
	int			j;
	t_fvector	v;
	
	i = 0;
	while (i < g->size.x)
	{
		j = 0;
		while (j < g->size.y / 2)
		{
			v.x = i;
			v.y = j;
			ft_draw_pixel(g, v, color);
			j++;
		}
		i++;
	}
}

void			ft_draw_ceiling(t_game *g, unsigned int color)
{
	int			i;
	int			j;
	t_fvector	v;
	
	i = 0;
	while (i < g->size.x)
	{
		j = g->size.y / 2;
		while (j < g->size.y)
		{
			v.x = i;
			v.y = j;
			ft_draw_pixel(g, v, color);
			j++;
		}
		i++;
	}
}

void			ft_draw_dir(t_game *g, unsigned int color)
{
	t_fvector v1;
	t_fvector v2;

	for (int i = -5; i < 5; i++)
		for (int j = -5; j < 5; j++)
			g->img.data[((int)((g->pos.y * TILESIZE + i)) * g->size.x + (int)(g->pos.x * TILESIZE + j))] = 0xFF000F;
	v1.x = TILESIZE * g->pos.x + TILESIZE * g->dir.x;
	v1.y = TILESIZE * g->pos.y + TILESIZE * g->dir.y;
	v2.x = TILESIZE * g->pos.x;
	v2.y =  TILESIZE * g->pos.y;
	ft_draw_line(g, v1, v2, color);
}