/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:44:45 by hopark            #+#    #+#             */
/*   Updated: 2021/03/09 11:14:27 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_ray_dda_init(t_game *g, t_ray *ray)
{
	if (ray->q == 2 || ray->q == 3)
	{
		ray->step.x = -1;
		ray->side.x = (g->pos.x - ray->map_pos.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map_pos.x + 1.0 - g->pos.x) * ray->delta.x;
	}
	if (ray->q == 1 || ray->q == 2)
	{
		ray->step.y = -1;
		ray->side.y = (g->pos.y - ray->map_pos.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map_pos.y + 1.0 - g->pos.y) * ray->delta.y;
	}
}

void			ft_ray_dda(t_game *g, t_ray *ray)
{
	while (ray->check == 0)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map_pos.x += ray->step.x;
			ray->dir = (ray->q == 2 || ray->q == 3) ? 'W' : 'E';
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map_pos.y += ray->step.y;
			ray->dir = (ray->q == 1 || ray->q == 2) ? 'N' : 'S';
		}
		ray->check = ft_check_iwall(g, ray->map_pos) == 1 ? 1 : 0;
	}
	ray->dis = (ray->map_pos.y - g->pos.y + (1 - ray->step.y) / 2) / ray->y;
	ray->point = g->pos.x + ray->dis * ray->x;
	if (ray->dir == 'W' || ray->dir == 'E')
	{
		ray->dis = (ray->map_pos.x - g->pos.x + (1 - ray->step.x) / 2) / ray->x;
		ray->point = g->pos.y + ray->dis * ray->y;
	}
}

void			ft_ray_casting(t_game *g)
{
	int				i;
	t_ray			ray;
	t_list			*cur;
	t_sprites		spr;

	ft_draw_floor(g, g->map.floor);
	ft_draw_ceiling(g, g->map.ceiling);
	i = -1;
	while (i++ < g->img.width)
	{
		ft_ray_init(g, &ray, i);
		ft_ray_dda_init(g, &ray);
		ft_ray_dda(g, &ray);
		ft_ray_draw(g, &ray, i);
		g_zbuffer[i] = ray.dis;
	}
	ft_sort_sprite(g);
	cur = g->spr;
	while (cur)
	{
		ft_sprite_init(g, cur, &spr);
		ft_sprite_draw(g, &spr);
		cur = cur->next;
	}
}
