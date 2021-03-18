/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:27:35 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 19:44:49 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_rgb_check(t_game *g, char **split, int num)
{
	unsigned int	color;
	char			**rgb;
	int				i;

	if (ft_component_check(g, num) == -1)
	{
		ft_free2(split, ft_strlen2(split));
		ft_exit_msg(g, "component error", 0);
	}
	if (ft_split_check(split, 2) == -1)
		ft_exit_msg(g, "not valid color", 0);
	rgb = ft_split(split[1], ',');
	if (ft_split_check(rgb, 3) == -1)
		ft_exit_msg(g, "not valid color", 0);
	i = 0;
	color = 0;
	while (i < 3)
	{
		color = color << 8;
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			ft_free2(split, ft_strlen2(split));
			ft_exit_msg(g, "notvalid color", 0);
		}
		color += ft_atoi(rgb[i]);
		i++;
	}
	ft_free2(rgb, ft_strlen2(rgb));
	return (color);
}
