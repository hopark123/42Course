/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:50:55 by hopark            #+#    #+#             */
/*   Updated: 2021/02/21 18:00:22 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_update_image(t_game *g)
{
	ft_ray_casting(g);
	ft_map_draw(g);
	ft_draw_dir(g, 0x00FFF0);
	mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
	mlx_do_sync(g->mlx);
	return (0);
}

int				ft_main_loop(t_game *g)
{
	static int update;

	update = 1;
	ft_img_init(g);
	if (g->turn.x || g->turn.y)
		update = ft_player_turn(g);
	if (g->move.x || g->move.y)
		update = ft_player_move(g);
	if (g->side.x || g->side.y)
		update = ft_player_side(g);
	if (update)
		ft_update_image(g);
	update = 0;
	return (0);
}
