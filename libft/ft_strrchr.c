/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:12:02 by hopark            #+#    #+#             */
/*   Updated: 2020/10/02 10:51:14 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	c2;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c2)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
