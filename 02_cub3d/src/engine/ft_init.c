/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:51:23 by hopark            #+#    #+#             */
/*   Updated: 2021/03/01 15:43:38 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_tex_init(t_game *g, int num, char *path)
{
	//printf("%d\n", num);
	//printf("%d\n", g->img.width);
	//printf("#%s#\n",path);
	(!(g->tex[num].ptr = mlx_xpm_file_to_image(g->mlx, path,\
					&g->tex[num].width, &g->tex[num].height)) ? ft_exit_msg(g, "failed to texture init1") : 0);
	(!(g->tex[num].data = (int *)mlx_get_data_addr(g->tex[num].ptr,\
					&g->tex[num].bpp, &g->tex[num].size_l, &g->tex[num].endian)) ? ft_exit_msg(g, "failed to texture init2") : 0);
}

void			ft_window_init(t_game *g)
{
	(!(g->mlx = mlx_init()) ? ft_exit_msg(g, "failed mlx init") : 0);
	(!(g->win = mlx_new_window(g->mlx, g->img.width, g->img.height, "mlx 42")) ? ft_exit_msg(g, "failed win init") : 0);
	ft_tex_init(g, 0, g->map.NO);
	ft_tex_init(g, 1, g->map.EA);
	ft_tex_init(g, 2, g->map.SO);
	ft_tex_init(g, 3, g->map.WE);
	ft_tex_init(g, 4, g->map.S);
}

void			ft_img_init(t_game *g)
{
	g->img.ptr = mlx_new_image(g->mlx, g->img.width, g->img.height);
	g->img.data = (int *)mlx_get_data_addr(g->img.ptr, &g->img.bpp,\
					&g->img.size_l, &g->img.endian);
	g->img.line = g->img.size_l / (g->img.bpp / 8);
}
