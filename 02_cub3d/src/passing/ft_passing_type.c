/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_passing_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:28:07 by hopark            #+#    #+#             */
/*   Updated: 2021/04/02 10:56:38 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_win_size(t_game *g, char **split)
{
	int		x;
	int		y;

	if (ft_component_check(g, 8) == -1)
		ft_exit_msg(g, "not valid render size", 0);
	if (ft_split_check(split, 3) == -1)
		ft_exit_msg(g, "not valid render size", 0);
	g->img.width = ft_min(ft_atoi(split[1]), WINDOWX);
	g->img.height = ft_min(ft_atoi(split[2]), WINDOWY);
	if (g->img.width < 0)
		ft_exit_msg(g, "not valid render size", 0);
	if (g->img.height < 0)
		ft_exit_msg(g, "not valid render size", 0);
}

void				ft_img_check(t_game *g, char **target,\
								char **split, int num)
{
	if (ft_component_check(g, num) == -1)
		ft_exit_msg(g, "component error", 0);
	if (ft_split_check(split, 2) == -1)
		ft_exit_msg(g, "component error", 0);
	*target = ft_strndup2(split[1], ft_strlen(split[1]));
}

int					ft_component_check(t_game *g, int num)
{
	if (g->map.flag >> num & 1)
		return (-1);
	g->map.flag |= 1 << num;
	return (1);
}

void				ft_passing_type(t_game *g, char **split)
{
	if (ft_memcmp(split[0], "R", 2) == 0)
		ft_win_size(g, split);
	else if (ft_memcmp(split[0], "NO", 3) == 0)
		ft_img_check(g, &g->map.no, split, 1);
	else if (ft_memcmp(split[0], "SO", 3) == 0)
		ft_img_check(g, &g->map.so, split, 2);
	else if (ft_memcmp(split[0], "WE", 3) == 0)
		ft_img_check(g, &g->map.we, split, 3);
	else if (ft_memcmp(split[0], "EA", 3) == 0)
		ft_img_check(g, &g->map.ea, split, 4);
	else if (ft_memcmp(split[0], "S", 2) == 0)
		ft_img_check(g, &g->map.s, split, 5);
	else if (ft_memcmp(split[0], "F", 2) == 0)
		g->map.floor = ft_rgb_check(g, split, 6);
	else if (ft_memcmp(split[0], "C", 2) == 0)
		g->map.ceiling = ft_rgb_check(g, split, 7);
	else
	{
		ft_free2(split, ft_strlen2(split));
		ft_exit_msg(g, "component error", 0);
	}
}
