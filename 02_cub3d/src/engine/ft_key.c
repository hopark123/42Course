/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:50:00 by hopark            #+#    #+#             */
/*   Updated: 2021/02/26 14:52:15 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_key_press(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		g->move.x = 1;
	else if (keycode == KEY_S)
		g->move.y = 1;
	if (keycode == KEY_D)
		g->side.x = 1;
	else if (keycode == KEY_A)
		g->side.y = 1;
	if (keycode == KEY_RIGHT)
		g->turn.x = 1;
	else if (keycode == KEY_LEFT)
		g->turn.y = 1;
	return (0);
}

int				ft_key_release(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		g->move.x = 0;
	else if (keycode == KEY_S)
		g->move.y = 0;
	if (keycode == KEY_D)
		g->side.x = 0;
	else if (keycode == KEY_A)
		g->side.y = 0;
	if (keycode == KEY_RIGHT)
		g->turn.x = 0;
	else if (keycode == KEY_LEFT)
		g->turn.y = 0;
	if (keycode == KEY_ESC)
		ft_exit_msg(g, "press ESC");
	return (0);
}
