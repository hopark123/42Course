/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:01:57 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 15:38:00 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_split_check(char **split, int num)
{
	if (ft_strlen2(split) != num)
		return (-1);
	return (1);
}

int				extention_check(char *path)
{
	int			len;

	if ((len = ft_strlen(path)) < 4)
		return (-1);
	if (path[len - 1] == 'b' && path[len - 2] == 'u' \
		&& path[len - 3] == 'c' && path[len - 4] == '.')
		return (1);
	return (-1);
}
