/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_passing_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:28:07 by hopark            #+#    #+#             */
/*   Updated: 2021/02/25 18:10:31 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_win_size(t_game *g, char **split)
{
	g->size.x = ft_atoi(split[1]);
	g->size.y = ft_atoi(split[2]);
}

int				ft_passing_type(t_game *g, char **split)
{
	if (ft_memcmp(split[0],"R", 1) == 0)
		ft_win_size(g, split);
	else if (ft_memcmp(split[0], "NO", 2) == 0)
		ft_tex_init(g, 0, split[1]);
	else if (ft_memcmp(split[0], "SO", 2) == 0)
		ft_tex_init(g, 1, split[1]);
	else if (ft_memcmp(split[0], "WE", 2) == 0)
		ft_tex_init(g, 2, split[1]);
	else if (ft_memcmp(split[0], "EA", 2) == 0)
		ft_tex_init(g, 3, split[1]);
	else if (ft_memcmp(split[0], "S", 1) == 0)
		ft_tex_init(g, 4, split[1]);
	//else if (ft_memcmp(split[0], "F", 1) == 0)
	//	g->map.floor = ft_RGB_check(split);
	//else if (ft_memcmp(split[0], "C", 1) == 0)
	//	g->map.ceiling = ft_RGB_check(split);
	else
		ft_exit_msg(g, "strange component");
	return(0);
}