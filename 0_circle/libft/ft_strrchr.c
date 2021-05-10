/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:12:02 by hopark            #+#    #+#             */
/*   Updated: 2020/10/15 13:31:51 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t			i;

	i = ft_strlen(s);
	while (s[i] != c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char *)s + i);
}
