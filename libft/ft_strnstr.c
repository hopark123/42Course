/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:12:01 by hopark            #+#    #+#             */
/*   Updated: 2020/10/02 11:01:55 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		llen;

	if (*little == '\0')
		return ((char *)big);
	llen = ft_strlen(little);
	while (i + llen <= len)
	{
		if (ft_strncmp(big + i, little, llen) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
