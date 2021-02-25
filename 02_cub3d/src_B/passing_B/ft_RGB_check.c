/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_RGB_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:27:35 by hopark            #+#    #+#             */
/*   Updated: 2021/02/19 16:47:27 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_RGB_check(char **split)
{
	unsigned int	color;
	char			**rgb;
	rgb = ft_split(split[1], ',');
	color = ft_atoi(rgb[0]);
	color = color << 8;
	color += ft_atoi(rgb[1]);
	color = color << 8;
	color += ft_atoi(rgb[2]);
	return (color);
}