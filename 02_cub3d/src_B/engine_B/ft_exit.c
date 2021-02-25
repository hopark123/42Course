/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:18:49 by hopark            #+#    #+#             */
/*   Updated: 2021/02/25 13:54:11 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			ft_free(void *memory)
{
	if (memory)
		free(memory);
}

void			ft_exit_msg(t_game *g, char *msg)
{
	write(1, "ERROR\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	ft_exit(g);
}

void			ft_exit(t_game *g)
{
	int		i;

	i = -1;
	while (i++ < 7)
		(g->tex[i].ptr ?  mlx_destroy_image(g->mlx, g->tex[i].ptr) : 0);
	i = -1;
	while (i++ < g->map.size.y)
		ft_free(g->map.m[i]);
	(g->img.ptr ? mlx_destroy_image(g->mlx, g->img.ptr) : 0);
	(g->win ? mlx_destroy_window(g->mlx, g->win) : 0);
}