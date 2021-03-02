/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:46:19 by hopark            #+#    #+#             */
/*   Updated: 2021/03/01 15:29:17 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_draw_pixel(t_game *g, t_fvector pt, unsigned int color)
{
	g->img.data[(int)pt.y * g->img.width + (int)pt.x] = color;
}

void			ft_draw_line(t_game *g, t_fvector v1, t_fvector v2, int color)
{
	float dx;
	float dy;
	float step;

	dx = (v2.x - v1.x);
	dy = (v2.y - v1.y);
	step = ft_max(fabs(dx), fabs(dy));
	dx /= step;
	dy /= step;
	while (fabs(v2.x - v1.x) > 1 || fabs(v2.y - v1.y) > 1)
	{
		g->img.data[(int)v1.y * g->img.width + (int)v1.x] = color;
		v1.x += dx;
		v1.y += dy;
	}
}

void			ft_draw_square(t_game *g, t_ivector pt,
							int size, unsigned int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			g->img.data[(size * pt.y + i) * g->img.width\
					+ size * pt.x + j] = color;
			j++;
		}
		i++;
	}
}
