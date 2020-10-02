/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:12:02 by hopark            #+#    #+#             */
/*   Updated: 2020/10/02 11:56:18 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t			i;

	i = ft_strlen(s);
	while (s[i] != c)
	{
		if (s[i] == 0)
			return (0);
		i--;
	}
	return ((char *)s + i);
}
