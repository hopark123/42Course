/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_passing_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:28:07 by hopark            #+#    #+#             */
/*   Updated: 2021/03/01 15:53:51 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_win_size(t_game *g, char **split)
{
	if (ft_component_check(g, 8) == -1)
		ft_exit_msg(g, "not valid render size0");
	if (ft_split_check(split, 3) == -1)
		ft_exit_msg(g, "not valid render size1");
	if ((g->img.width = ft_atoi(split[1])) < 0)
		ft_exit_msg(g, "not valid render size2");
	if ((g->img.height = ft_atoi(split[2])) < 0)
		ft_exit_msg(g, "not valid render size3");
}

void				ft_img_check(t_game *g, char **target, char **split, int num)
{
	if (ft_component_check(g, num) == -1)
		ft_exit_msg(g, "component error10");
	if (ft_split_check(split, 2) == -1)
		ft_exit_msg(g, "component error11");
	*target = split[1];
}


int				ft_component_check(t_game	*g, int num)
{
	if (g->map.flag  >> num & 1)
		return (-1);
	g->map.flag |= 1 << num;
	return (1);
}

void				ft_passing_type(t_game *g, char **split)
{
	if (ft_memcmp(split[0],"R", 2) == 0)
		ft_win_size(g, split);
	else if (ft_memcmp(split[0], "NO", 3) == 0)
		ft_img_check(g, &g->map.NO, split, 1);
	else if (ft_memcmp(split[0], "SO", 3) == 0)
		ft_img_check(g, &g->map.SO, split, 2);
	else if (ft_memcmp(split[0], "WE", 3) == 0)
		ft_img_check(g, &g->map.WE, split, 3);
	else if (ft_memcmp(split[0], "EA", 3) == 0)
		ft_img_check(g, &g->map.EA, split, 4);
	else if (ft_memcmp(split[0], "S", 2) == 0)
		ft_img_check(g, &g->map.S, split, 5);
	else if (ft_memcmp(split[0], "F", 2) == 0)
		g->map.floor = ft_RGB_check(g, split, 6);
	else if (ft_memcmp(split[0], "C", 2) == 0)
		g->map.ceiling = ft_RGB_check(g, split, 7);
	else
		ft_exit_msg(g, "component error3");
}