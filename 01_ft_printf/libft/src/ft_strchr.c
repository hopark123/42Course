/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:50:21 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 18:24:49 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t				i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == 0)
			return (0);
		i++;
	}
	return ((char *)s + i);
}