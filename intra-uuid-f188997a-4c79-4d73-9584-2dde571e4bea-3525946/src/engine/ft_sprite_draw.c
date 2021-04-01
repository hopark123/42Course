/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:44:26 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 17:00:20 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_lswap(t_list *s1, t_list *s2)
{
	t_fvector		temp;

	temp = s1->pt;
	s1->pt = s2->pt;
	s2->pt = temp;
	ft_fswap(&s1->dis, &s2->dis);
}

void			ft_sort_sprite(t_game *g)
{
	t_list		*cur;
	t_list		*temp;

	cur = g->spr;
	while (cur)
	{
		cur->dis = sqrt((g->pos.x - cur->pt.x) * (g->pos.x - cur->pt.x) \
						+ (g->pos.y - cur->pt.y) * (g->pos.y - cur->pt.y));
		cur = cur->next;
	}
	cur = g->spr;
	while (cur)
	{
		temp = cur->next;
		while (temp)
		{
			if (cur->dis < temp->dis)
				ft_lswap(cur, temp);
			temp = temp->next;
		}
		cur = cur->next;
	}
}

void			ft_sprite_init(t_game *g, t_list *cur, t_sprites *spr)
{
	spr->temp.x = cur->pt.x - g->pos.x;
	spr->temp.y = cur->pt.y - g->pos.y;
	spr->trans = ft_i_matrix_multi(g->plane, g->dir, spr->temp);
	spr->scx = (g->img.width / 2) * (1 + spr->trans.x / spr->trans.y);
	spr->sprite.y = fabs((g->img.height / spr->trans.y));
	spr->sprite.x = fabs((g->img.width / spr->trans.y));
}

void			ft_sprite_draw(t_game *g, t_sprites *spr)
{
	t_draw		draw;

	draw.start.x = ft_max(spr->scx - spr->sprite.x / 2, 0);
	draw.end.x = ft_min(spr->scx + spr->sprite.x / 2, g->img.width - 1);
	while (draw.start.x < draw.end.x)
	{
		draw.start.y = ft_max((g->img.height - spr->sprite.y) / 2, 0);
		draw.end.y = ft_min((g->img.height + spr->sprite.y)\
						/ 2, g->img.height - 1);
		draw.pixel.x = (int)(256 * (draw.start.x - (spr->scx -\
					spr->sprite.x / 2)) * SPR_SIZE / spr->sprite.x / 256);
		if (spr->trans.y > 0 && spr->trans.y < g_zbuffer[(int)draw.start.x])
			while (draw.start.y < draw.end.y)
			{
				draw.step.y = draw.start.y * 256 -\
								g->img.height * 128 + spr->sprite.y * 128;
				draw.pixel.y = (int)(draw.step.y * SPR_SIZE /\
								spr->sprite.y / 256);
				draw.color = g->tex[4].data[(int)(draw.pixel.y * SPR_SIZE) \
												+ (int)draw.pixel.x];
				ft_draw_pixel(g, draw.start, draw.color);
				draw.start.y++;
			}
		draw.start.x++;
	}
}
