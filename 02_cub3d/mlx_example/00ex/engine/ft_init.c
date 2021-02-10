/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:51:23 by hopark            #+#    #+#             */
/*   Updated: 2021/02/10 16:32:50 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_tex_init(t_game *g, int num, char *path)
{
	g->tex[num].ptr = mlx_xpm_file_to_image(g->mlx, path,\
					&g->tex[num].width, &g->tex[num].height);
	g->tex[num].data = (int *)mlx_get_data_addr(g->tex[num].ptr,\
					&g->tex[num].bpp, &g->tex[num].size_l, &g->tex[num].endian);
}

void			ft_window_init(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
}

void			ft_img_init(t_game *g)
{
	int			i;
	
	g->img.ptr = mlx_new_image(g->mlx, IMG_WIDTH, IMG_HEIGHT);
	g->img.data = (int *)mlx_get_data_addr(g->img.ptr, &g->img.bpp,\
					&g->img.size_l, &g->img.endian);
	i = 0;
	ft_tex_init(g, 0, "img/wall_n.xpm");
	ft_tex_init(g, 1, "img/wall_s.xpm");
	ft_tex_init(g, 2, "img/wall_W.xpm");
	ft_tex_init(g, 3, "img/wall_E.xpm");
	ft_tex_init(g, 4, "img/bird.xpm");
	ft_tex_init(g, 5, "img/tree.xpm");
	ft_draw_floor(g, g->map.floor);
	ft_draw_ceiling(g, g->map.ceiling);
	ft_map_check(g, 0);
}
