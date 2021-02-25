/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:40:30 by hopark            #+#    #+#             */
/*   Updated: 2021/02/21 18:00:12 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_ray_quadrant(t_ray *ray)
{
	if (ray->x >= 0 && ray->y < 0)
		ray->q = 1;
	else if (ray->x < 0 && ray->y < 0)
		ray->q = 2;
	else if (ray->x < 0 && ray->y >= 0)
		ray->q = 3;
	else if (ray->x >= 0 && ray->y >= 0)
		ray->q = 4;
}

void			ft_ray_init(t_game *g, t_ray *ray, int i)
{
	ray->check = 0;
	ray->map_pos.x = (int)g->pos.x;
	ray->map_pos.y = (int)g->pos.y;
	ray->cam = 2 * i / (float)g->size.x - 1;
	ray->x = g->dir.x + g->plane.x * ray->cam;
	ray->y = g->dir.y + g->plane.y * ray->cam;
	ft_ray_quadrant(ray);
	ray->delta.x = fabs(1 / ray->x);
	ray->delta.y = fabs(1 / ray->y);
}

unsigned int	ft_choice_tex(t_game *g, t_draw draw, char dir)
{
	unsigned int	color;
	int				tex_num;
	
	if (dir == 'N')
		tex_num = 0;
	else if (dir == 'S')
		tex_num = 1;
	else if (dir == 'W')
		tex_num = 2;
	else
		tex_num = 3;
	color = g->tex[tex_num].data[(int)(draw.tex.y * TEXTURE_SIZE)\
				* TEXTURE_SIZE + (int)draw.tex.x];
	return (color);
}

void			ft_ray_draw(t_game *g, t_ray *ray, int i)
{
	t_draw			draw;

	ray->len = g->size.x / 3 / ray->dis / tan(FOV_ANGLE / 2);
	draw.pixel.y = ray->len > g->size.y ? (ray->len - g->size.y) / 2 : 0;
	draw.start.y = ft_max((g->size.y - ray->len) / 2, 0);
	draw.end.y = ft_min((g->size.y + ray->len) / 2, g->size.y - 1);
	draw.start.x = i;
	while (draw.start.y < draw.end.y)
	{
		draw.tex.x = (ray->point - floor(ray->point)) * TEXTURE_SIZE;
		if (ray->dir == 'W' || ray->dir == 'S')
			draw.tex.x = TEXTURE_SIZE - draw.tex.x - 1;
		draw.tex.y = draw.pixel.y / ray->len;
		draw.color = ft_choice_tex(g, draw, ray->dir);
		ft_draw_pixel(g, draw.start, draw.color);
		draw.start.y++;
		draw.pixel.y++;
	}
}
