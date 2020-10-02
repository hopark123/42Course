/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:11:55 by hopark            #+#    #+#             */
/*   Updated: 2020/10/02 11:06:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	unsigned char		c2;

	c2 = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
