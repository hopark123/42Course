/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:51:23 by hopark            #+#    #+#             */
/*   Updated: 2021/03/09 13:31:30 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_tex_init(t_game *g, int num, char *path)
{
	(!(g->tex[num].ptr = mlx_xpm_file_to_image(g->mlx, path,\
					&g->tex[num].width, &g->tex[num].height)) ? \
					ft_exit_msg(g, "fail to texture init", 0) : 0);
	(!(g->tex[num].data = (int *)mlx_get_data_addr(g->tex[num].ptr,\
					&g->tex[num].bpp, &g->tex[num].size_l,\
					&g->tex[num].endian)) ? \
					ft_exit_msg(g, "fail to texture init", 0) : 0);
}

void			ft_window_init(t_game *g)
{
	(!(g->mlx = mlx_init()) ?\
							ft_exit_msg(g, "fail mlx init", 0) : 0);
	(!(g->win = mlx_new_window(g->mlx, g->img.width, g->img.height,\
							"mlx 42")) ?\
							ft_exit_msg(g, "fail win init", 0) : 0);
	ft_tex_init(g, 0, g->map.no);
	ft_tex_init(g, 1, g->map.ea);
	ft_tex_init(g, 2, g->map.so);
	ft_tex_init(g, 3, g->map.we);
	ft_tex_init(g, 4, g->map.s);
}

void			ft_img_init(t_game *g)
{
	g->img.ptr = mlx_new_image(g->mlx, g->img.width, g->img.height);
	g->img.data = (int *)mlx_get_data_addr(g->img.ptr, &g->img.bpp,\
					&g->img.size_l, &g->img.endian);
	g->img.line = g->img.size_l / (g->img.bpp / 8);
}
