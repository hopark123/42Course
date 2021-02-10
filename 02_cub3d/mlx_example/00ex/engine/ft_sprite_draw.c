/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:44:26 by hopark            #+#    #+#             */
/*   Updated: 2021/02/10 16:42:35 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				*ft_sort_sprite(t_game *g, t_sprite *sprite)
{
	float		distance[numSprites];
	int			*order;
	int			i;
	int			j;

	if (!(order = malloc(sizeof(int) * (numSprites + 1))))
		return (0);
	i = 0;
	while (i < numSprites)
	{
		distance[i] = sqrt((g->pos.x - sprite[i].x) * (g->pos.x - sprite[i].x)\
						+ (g->pos.y - sprite[i].y) * (g->pos.y - sprite[i].y)); 
		order[i] = i;
		i++;
	}
	i = 0;
	while (i < numSprites)
	{
		j = i;
		while (j < numSprites)
		{
			if (distance[i] < distance[j])
			{
				ft_fswap(&distance[i], &distance[j]);
				ft_iswap(&order[i], &order[j]);
			}
			j++;
		}
		i++;
	}
	return (order);
}

void			ft_sprite_init(t_game *g, t_sprites *spr, int	order)
{
	spr->temp.x = sprite[order].x - g->pos.x;
	spr->temp.y = sprite[order].y - g->pos.y;
	spr->num = sprite[order].num;
	spr->trans = ft_i_matrix_mulit(g->plane, g->dir, spr->temp);
	spr->screenX = (WIN_WIDTH / 2) * (1 + spr->trans.x / spr->trans.y);
	spr->sprite.y = fabs((IMG_HEIGHT / spr->trans.y));
	spr->sprite.x = fabs((IMG_WIDTH / spr->trans.y));
}

void			ft_sprite_draw(t_game *g, t_sprites *spr)
{
	t_draw		draw;
	
	draw.start.x = ft_max(spr->screenX - spr->sprite.x / 2, 0);
	draw.end.x = ft_min(spr->screenX + spr->sprite.x / 2, IMG_WIDTH - 1);
	while (draw.start.x < draw.end.x)
	{
		draw.start.y = ft_max((IMG_HEIGHT - spr->sprite.y) / 2, 0);
		draw.end.y = ft_min((IMG_HEIGHT + spr->sprite.y) / 2, IMG_HEIGHT - 1);
		draw.pixel.x = (int)(256 * (draw.start.x - (spr->screenX - spr->sprite.x / 2)) *\
						SPRITE_SIZE / spr->sprite.x  / 256);
		if (spr->trans.y > 0 && spr->trans.y < ZBUFFER[(int)draw.start.x])
			while (draw.start.y < draw.end.y)
			{
				draw.step.y = draw.start.y * 256 - IMG_HEIGHT * 128 + spr->sprite.y * 128;
				draw.pixel.y = (int)(draw.step.y * SPRITE_SIZE / spr->sprite.y / 256);
				draw.color = g->tex[spr->num].data[(int)(draw.pixel.y * SPRITE_SIZE) \
												+ (int)draw.pixel.x];
				if ((draw.color & 0x00FFFFFF) != 0)
					ft_draw_pixel(g, draw.start, draw.color);
				draw.start.y++;
			}
		draw.start.x++;
	}
}
