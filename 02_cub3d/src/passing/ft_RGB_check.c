/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_RGB_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:27:35 by hopark            #+#    #+#             */
/*   Updated: 2021/03/01 12:30:37 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_RGB_check(t_game *g, char **split, int num)
{
	unsigned int	color;
	char			**rgb;
	int				i;

	if (ft_component_check(g, num) == -1)
		ft_exit_msg(g, "component error10");
	if (ft_split_check(split, 2) == -1)
		ft_exit_msg(g, "not valid color122");
	
	rgb = ft_split(split[1], ',');
	if (ft_split_check(rgb, 3) == -1)
		ft_exit_msg(g, "not valid color2");
	i = 0;
	color = 0;
	while (i < 3)
	{
		color = color << 8;
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			ft_exit_msg(g, "notvalid color3");
		color += ft_atoi(rgb[i]);
		i++;
	}
	return (color);
}