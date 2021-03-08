/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:18:49 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 15:12:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_free(void *memory)
{
	if (memory)
		free(memory);
}

void				ft_free2(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

void				ft_exit_msg(t_game *g, char *msg)
{
	write(1, "ERROR\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	ft_exit(g);
}

int					mlx_destroy_display(void *mlx_ptr)
{
	return (mlx_ptr ? 0 : 1);
}

void				ft_exit(t_game *g)
{
	int		i;

	i = -1;
	while (i++ < 4)
		(g->tex[i].ptr ? mlx_destroy_image(g->mlx, g->tex[i].ptr) : 0);
	i = -1;
	ft_free2(g->map.m, g->map.size.y);
	(g->img.ptr ? mlx_destroy_image(g->mlx, g->img.ptr) : 0);
	(g->win ? mlx_destroy_window(g->mlx, g->win) : 0);
	exit(0);
}
