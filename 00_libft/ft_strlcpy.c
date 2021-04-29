/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:11:57 by hopark            #+#    #+#             */
/*   Updated: 2020/10/01 13:42:08 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len;
	size_t i;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dst == 0 || size == 0)
		return (src_len);
	i = 0;
	while (i < src_len && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}
