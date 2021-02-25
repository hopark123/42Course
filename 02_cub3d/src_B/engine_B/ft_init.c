/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:51:23 by hopark            #+#    #+#             */
/*   Updated: 2021/02/25 13:42:13 by hopark           ###   ########.fr       */
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
	(!(g->mlx = mlx_init()) ? ft_exit_msg(g, "failed mlx init") : 0);
	(!(g->win = mlx_new_window(g->mlx, g->size.x, g->size.y, "mlx 42")) ? ft_exit_msg(g, "failed win init") : 0);
}

void			ft_img_init(t_game *g)
{
	g->img.ptr = mlx_new_image(g->mlx, g->size.x, g->size.y);
	g->img.data = (int *)mlx_get_data_addr(g->img.ptr, &g->img.bpp,\
					&g->img.size_l, &g->img.endian);

}
