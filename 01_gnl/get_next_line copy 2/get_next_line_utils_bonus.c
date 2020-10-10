/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:08:30 by hopark            #+#    #+#             */
/*   Updated: 2020/10/10 20:45:28 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strchr(char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == 0)
			return (0);
		i++;
	}
	return ((char *)s + i);
}

char		*ft_strncpy(char *dst, char *src, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char		*ft_strncat_free(char *dst, char *src, size_t size)
{
	char		*res;
	size_t		dst_len;

	dst_len = ft_strlen(dst);
	if (!(res = (char *)malloc(sizeof(char) * (dst_len + size + 1))))
		return (0);
	ft_strncpy(res, dst, dst_len);
	ft_strncpy(res + dst_len, src, size);
	if (dst != 0)
		free(dst);
	return (res);
}
