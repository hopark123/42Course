/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:57:57 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 15:30:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		llen;

	if (*little == 0)
		return ((char *)big);
	llen = ft_strlen(little);
	i = 0;
	if (*big == 0)
		return (0);
	while (i + llen <= len)
	{
		if (ft_strncmp(big + i, little, llen) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
